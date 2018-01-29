#include "PlayScene.h"
#include <ctime>
#include <cstdlib>
using namespace std;


PlayScene::PlayScene() {
	srand(time(nullptr));
	
	song.openFromFile("Resources/Music/MissionTheme.ogg");
	song.setLoop(true);
	song.setVolume(5);
	song.play();
	
	playerbuffer.loadFromFile("Resources/Sounds/AlliedGunfire.wav");
	playerGunFire.setBuffer(playerbuffer);
	
	missilBuffer.loadFromFile("Resources/Sounds/LaunchMissile.wav");
	launchMissil.setBuffer(missilBuffer);
	launchMissil.setVolume(50);
	
	enemyBuffer.loadFromFile("Resources/Sounds/EnemyGunFire.wav");
	enemyGunFire.setBuffer(enemyBuffer);
	enemyGunFire.setVolume(40);
	
	explosionBuffer.loadFromFile("Resources/Sounds/Explosion1.wav");
	explosionSound.setBuffer(explosionBuffer);
	
	itemBuffer.loadFromFile("Resources/Sounds/CollectPickUp.wav");
	itemPickUp.setBuffer(itemBuffer);
	
	score = 0;
	font.loadFromFile("Resources/Fonts/Sansation.ttf");
	txtScore.setFont(font);
	txtScore.setPosition(585, 10);
	txtGameOver.setFont(font);
	txtGameOver.setPosition(200, 200);
	txtNewRecord.setFont(font);
	txtNewRecord.setPosition(200, 250);
	
	for (int i=0; i<5; i++){
		Enemy* enemy = new Enemy();
		enemies.push_back(*enemy);
	}
	
	for (int i=0; i<3; i++){
		Enemy2 *enemy2 = new Enemy2();
		specialEnemies.push_back(*enemy2);
	}
	
	timeToNextItem = sf::seconds(30);
	delayItem = 0;
}

void PlayScene::processEvent(sf::RenderWindow &w, sf::Event &event){
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Space){
			Bullet *bullet = new Bullet(player.getPosition().x + 22, player.getPosition().y);
			bullet->setRotation(0);
			bullet->setSpeed();
			playerBullets.push_back(*bullet);
			
			playerGunFire.play();
		}
		if (event.key.code == sf::Keyboard::M && missilAmmo > 0){
			Missil *newMisil1 = new Missil(player.getPosition().x + 15, player.getPosition().y + 30);
			newMisil1->setDirectionX(-200.0f);
			Missil *newMisil2 = new Missil(player.getPosition().x + 15, player.getPosition().y + 30);
			newMisil2->setDirectionX(0);
			Missil *newMisil3 = new Missil(player.getPosition().x + 15, player.getPosition().y + 30);
			newMisil3->setDirectionX(200.0f);
			misils.push_back(*newMisil1);
			misils.push_back(*newMisil2);
			misils.push_back(*newMisil3);
			
			missilAmmo--;
			
			launchMissil.play();
		}
		if ((event.key.code == sf::Keyboard::Space) && player.isDead()){
			Game::getInstance().switchScene(new MenuScene());
		}
	}
}

void PlayScene::update (float elapsed) {
	BaseScene::update(elapsed);
	
	background.update(elapsed);
	
	player.update(elapsed);
	
	for (size_t i=0; i<enemies.size(); i++){
		enemies[i].update(elapsed);
		
		if (enemies[i].fireEvent(elapsed)){
			Bullet *bullet = new Bullet(enemies[i].getPosition().x-33, enemies[i].getPosition().y-34);
			bullets.push_back(*bullet);
			
			enemyGunFire.play();
		}
		
		if (enemies[i].getBounds().intersects(player.getBounds())){
			player.getHit(30);
			
			Explosion *newExplosion = new Explosion(enemies[i].getPosition().x-104, enemies[i].getPosition().y-98);
			enemiesExplosions.push_back(*newExplosion);
			explosionSound.play();
			
			enemies.erase(enemies.begin() + i);
		}
	}
	
	for (size_t i=0; i<specialEnemies.size(); i++){
		specialEnemies[i].update(elapsed);
		
		if (specialEnemies[i].fireEvent(elapsed)){
			Bullet *otherbullet = new Bullet(specialEnemies[i].getPosition().x-33, specialEnemies[i].getPosition().y-34);
			bullets.push_back(*otherbullet);
			
			enemyGunFire.play();
		}
		
		if (specialEnemies[i].getBounds().intersects(player.getBounds())){
			player.getHit(30);
			
			Explosion *newExplosion = new Explosion(specialEnemies[i].getPosition().x-104, specialEnemies[i].getPosition().y-98);
			enemiesExplosions.push_back(*newExplosion);
			explosionSound.play();
			
			specialEnemies.erase(specialEnemies.begin() + i);
		}
	}
	
	//cuando el vector de enemigos especiales queda vacio se crean 3 mas y se aumenta su velocidad
	if (specialEnemies.empty()){
		for (int i=0; i<3; i++){
			Enemy2* newEnemy = new Enemy2();
			newEnemy->speedUp(addSpeed);
			std::cout<<newEnemy->getSpeed()<<std::endl;
			specialEnemies.push_back(*newEnemy);
		}
		addSpeed += 10.0f;
	}
	
	for (size_t i=0; i<bullets.size(); i++){
		bullets[i].update(elapsed);
		
		if (bullets[i].getPosition().y >480+5){
			bullets.erase(bullets.begin() + i);
		}
		
		if (bullets[i].getBounds().intersects(player.getBounds())){
			player.getHit(10);
			bullets.erase(bullets.begin()+i);
		}
	}
	
	//si las balas se van de los limites de la pantalla son eliminadas del vector
	for (size_t i=0; i<playerBullets.size(); i++){
		playerBullets[i].update(elapsed);
		
		if (playerBullets[i].getPosition().y <= 0){
			playerBullets.erase(playerBullets.begin()+i);
		}
	}
	
	
	for (size_t j=0; j<playerBullets.size(); j++){
		//se detectan las colisiones con los enemigos normales
		for (size_t i=0; i<enemies.size(); i++){
			if (enemies[i].getBounds().intersects(playerBullets[j].getBounds())){
				Explosion *newExplosion = new Explosion(enemies[i].getPosition().x-104, enemies[i].getPosition().y-98);
				enemiesExplosions.push_back(*newExplosion);
				explosionSound.play();
				
				enemies.erase(enemies.begin() + i);
				playerBullets.erase(playerBullets.begin() + j);
				Enemy *enemy = new Enemy();
				enemies.push_back(*enemy);
				
				score += 15;
			}
		}
		
		//se detectan las colisiones con los enemigos especiales
		for (size_t i=0; i<specialEnemies.size(); i++){
			if (playerBullets[j].getBounds().intersects(specialEnemies[i].getBounds())){
				Explosion *newExplosion = new Explosion(specialEnemies[i].getPosition().x-104, 
														specialEnemies[i].getPosition().y-98);
				enemiesExplosions.push_back(*newExplosion);
				explosionSound.play();
				
				specialEnemies.erase(specialEnemies.begin() + i);
				playerBullets.erase(playerBullets.begin() + j);
				
				score += 20;
			}
		}
	}
	
	for (size_t i=0; i<misils.size(); i++){
		misils[i].update(elapsed);
		
		if ((misils[i].getPosition().x < 0) || (misils[i].getPosition().x > 640)){
			misils.erase(misils.begin() + i);
		}
		if (misils[i].getPosition().y < 0){
			misils.erase(misils.begin() + i);
		}
	}
	
	for (int j=0; j<misils.size(); j++){
		//se detectan las colisiones con los enemigos normales
		for (size_t i=0; i<enemies.size(); i++){
			if (misils[j].getBounds().intersects(enemies[i].getBounds())){
				Explosion *newExplosion = new Explosion(enemies[i].getPosition().x-104, enemies[i].getPosition().y-98);
				enemiesExplosions.push_back(*newExplosion);
				explosionSound.play();
				
				enemies.erase(enemies.begin() + i);
				misils.erase(misils.begin() + j);
				Enemy *enemy = new Enemy();
				enemies.push_back(*enemy);
				
				score += 15;
			}
		}
		
		//se detectan las colisiones con los enemigos especiales
		for (size_t i=0; i<specialEnemies.size(); i++){
			if (misils[j].getBounds().intersects(specialEnemies[i].getBounds())){
				Explosion *newExplosion = new Explosion(specialEnemies[i].getPosition().x-104, 
														specialEnemies[i].getPosition().y-98);
				enemiesExplosions.push_back(*newExplosion);
				explosionSound.play();
				
				specialEnemies.erase(specialEnemies.begin() + i);
				misils.erase(misils.begin() + j);
				
				score += 20;
			}
		}
	}
	
	
	for (size_t i=0; i<enemiesExplosions.size(); i++){
		enemiesExplosions[i].update(elapsed);
		if (enemiesExplosions[i].isFinished()){
			enemiesExplosions.erase(enemiesExplosions.begin()+i);
		}
	}
	
	std::stringstream ss;
	ss<<score;
	txtScore.setString(ss.str());
	
	if (player.isDead()){
		string gameOverMessage = "Juego Terminado";
		
		//Explosion* playerExplosion = new Explosion(player.getPosition().x, player.getPosition().y);
		//enemiesExplosions.push_back(*playerExplosion);
		
		//cuando el jugador muere se abre el ultimo puntaje guardado y se compara con el nuevo 
		//para mostrar siempre el mayor puntaje obtenido
		std::ifstream archi("puntajes.dat", ios::binary);
		int scoreComp;
		archi.read(reinterpret_cast<char*>(&scoreComp), sizeof(int));
		archi.close();
		
		if (score > scoreComp){
			std::ofstream archi2("puntajes.dat", ios::binary | ios::trunc);
			archi2.write(reinterpret_cast<char*>(&score), sizeof(int));
			archi2.close();
			
			string newRecorMessage = "Nuevo Record!";
			txtNewRecord.setString(newRecorMessage);
		}
		
		txtGameOver.setString(gameOverMessage);
		gamePause();
		song.stop();
	}
	
	delayItem += elapsed;
	//ademas de cumplir el tiempo el item debe estar fuera de la pantalla
	//para no cambiar la textura en medio del juego
	if ((delayItem >= timeToNextItem.asSeconds()) && (item.getPosition().y < 0)){
		while (delayItem >= timeToNextItem.asSeconds()){
			delayItem -= timeToNextItem.asSeconds();
		}
		
		switch (1 + rand() % (3-1)){
		case 1:
			item.changeTexture("Resources/Textures/HealthRefill.png");
			item.setTextureTracker(1);
			break;
		case 2:
			item.changeTexture("Resources/Textures/MissileRefill.png");
			item.setTextureTracker(2);
			break;
		}
		item.startMoving();
		
		//el tiempo que tarda en aparecer el proximo item se establece aleatoriamente entre 1 y 3 minutos
		timeToNextItem = sf::seconds(60 + rand() % (181 - 60));
	}
	item.update(elapsed);
	
	if (item.getBounds().intersects(player.getBounds())){
		itemPickUp.play();
		item.resetPos();
		
		if (item.getTextureTracker() == 1){
			player.heal();
		}else if (item.getTextureTracker() == 2){
			missilAmmo = 2;
		}
	}
}

void PlayScene::gamePause(){
	player.pause();
	background.pause();
	for (size_t i=0; i<enemies.size(); i++){
		enemies[i].pause();
	}
	for (size_t i=0; i<specialEnemies.size(); i++){
		specialEnemies[i].pause();
	}
	for (size_t i=0; i<bullets.size(); i++){
		bullets[i].pause();
	}
	for (size_t i=0; i<playerBullets.size(); i++){
		playerBullets[i].pause();
	}
	for (size_t i=0; i<misils.size(); i++){
		misils[i].pause();
	}
}

void PlayScene::draw (sf::RenderWindow & w) {
	BaseScene::draw(w);
	background.draw(w);
	for (size_t i=0; i<bullets.size(); i++){
		bullets[i].draw(w);
	}
	for (size_t i=0; i<enemies.size(); i++){
		enemies[i].draw(w);
	}
	for (size_t i=0; i<specialEnemies.size(); i++){
		specialEnemies[i].draw(w);
	}
	for (size_t i=0; i<playerBullets.size(); i++){
		playerBullets[i].draw(w);
	}
	for (size_t i=0; i<enemiesExplosions.size(); i++){
		enemiesExplosions[i].draw(w);
	}
	for (size_t i=0; i<misils.size(); i++){
		misils[i].draw(w);
	}
	item.draw(w);
	player.draw(w);
	w.draw(txtScore);
	w.draw(txtGameOver);
	w.draw(txtNewRecord);
}

