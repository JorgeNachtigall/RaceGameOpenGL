#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <string.h>

#define TAMJANELA 600
#define POSJANELA 10

int min = 150;
int max = 430;
char end[8];
int endAnimation = 0;
int lives = 3;
int endLine = 600;
float carMapPos = 30;
bool isColliding = false;
int playerLeft;
int playerRight;
int movex=0;
int dir = 0;
int enemyMove = -1;
int enemyX = rand() % (max - min) + min;
int enemyY = 600;

void Start(void){
  glClearColor(0, 0, 0, 0);
}

void drawGrass(){
	glColor3f(.2,.5,0);
	glBegin(GL_POLYGON);
    	glVertex2i(0, 0);
    	glVertex2i(150, 0);
    	glVertex2i(150, 600);
    	glVertex2i(0, 600);
    	glVertex2i(0, 0);
  	glEnd();

  	glBegin(GL_POLYGON);
    	glVertex2i(450, 0);
    	glVertex2i(600, 0);
    	glVertex2i(600, 600);
    	glVertex2i(450, 600);
    	glVertex2i(450, 0);
  	glEnd();
}

void drawPlayer(){
	glColor3f(1,0,0);

	glBegin(GL_POLYGON);
    	glVertex2i(260+movex, 25 + endAnimation); // 1
    	glVertex2i(280+movex, 25 + endAnimation); // 2
    	glVertex2i(280+movex, 85 + endAnimation); // 19
    	glVertex2i(270+movex, 95 + endAnimation); // 20
    	glVertex2i(260+movex, 85 + endAnimation); // 21
    	glVertex2i(260+movex, 25 + endAnimation); // 1
    glEnd();

    // ligação direita traseira
    glColor3f(.8,.8,.8);
    glBegin(GL_POLYGON);
    	glVertex2i(280+movex, 30 + endAnimation); // 3
    	glVertex2i(285+movex, 30 + endAnimation); // 4
    	glVertex2i(285+movex, 40 + endAnimation); // 9
		glVertex2i(280+movex, 40 + endAnimation); // 10
		glVertex2i(280+movex, 30 + endAnimation); // 3
	glEnd();

	glColor3f(.3,.3,.3);
	// roda direita traseira
	glBegin(GL_POLYGON);
    	glVertex2i(285+movex, 25 + endAnimation); // 5
    	glVertex2i(295+movex, 25 + endAnimation); // 6
    	glVertex2i(295+movex, 45 + endAnimation); // 7
    	glVertex2i(285+movex, 45 + endAnimation); // 8
    	glVertex2i(285+movex, 25 + endAnimation); // 5
    glEnd();

    playerRight = 295 + movex;

    glColor3f(.8,.8,.8);
    // ligação direita dianteira
    glBegin(GL_POLYGON);	
    	glVertex2i(280+movex, 60 + endAnimation); // 11
    	glVertex2i(285+movex, 60 + endAnimation); // 12
    	glVertex2i(285+movex, 70 + endAnimation); // 17
    	glVertex2i(280+movex, 70 + endAnimation); // 18
    	glVertex2i(280+movex, 60 + endAnimation); // 11
    glEnd();

    glColor3f(.3,.3,.3);
    // roda direita dianteira
    glBegin(GL_POLYGON);	
    	glVertex2i(285+movex, 55 + endAnimation); // 13
    	glVertex2i(295+movex, 55 + endAnimation); // 14
    	glVertex2i(295+movex, 75 + endAnimation); // 15
    	glVertex2i(285+movex, 75 + endAnimation); // 16
    	glVertex2i(285+movex, 55 + endAnimation); // 13
    glEnd();

    glColor3f(.8,.8,.8);
    //ligação esquerda dianteira
    glBegin(GL_POLYGON);
    	glVertex2i(255+movex, 60 + endAnimation); // 28
    	glVertex2i(260+movex, 60 + endAnimation); // 29
    	glVertex2i(260+movex, 70 + endAnimation); // 22
    	glVertex2i(255+movex, 70 + endAnimation); // 23
    	glVertex2i(255+movex, 60 + endAnimation); // 28
    glEnd();

    glColor3f(.3,.3,.3);
    //roda esquerda dianteira
    glBegin(GL_POLYGON);
    	glVertex2i(245+movex, 55 + endAnimation); // 26
    	glVertex2i(255+movex, 55 + endAnimation); // 27
    	glVertex2i(255+movex, 75 + endAnimation); // 24
    	glVertex2i(245+movex, 75 + endAnimation); // 25
    	glVertex2i(245+movex, 55 + endAnimation); // 26
    glEnd();

    playerLeft = 245 + movex;

    glColor3f(.8,.8,.8);
    //ligação esquerda traseira
    glBegin(GL_POLYGON);
    	glVertex2i(255+movex, 30 + endAnimation); // 36
    	glVertex2i(260+movex, 30 + endAnimation); // 37
    	glVertex2i(260+movex, 40 + endAnimation); // 30
    	glVertex2i(255+movex, 40 + endAnimation); // 31
    	glVertex2i(255+movex, 30 + endAnimation); // 36
    glEnd();

    glColor3f(.3,.3,.3);
    //roda esquerda traseira
    glBegin(GL_POLYGON);
    	glVertex2i(245+movex, 25 + endAnimation); // 34
    	glVertex2i(255+movex, 25 + endAnimation); // 35
    	glVertex2i(255+movex, 45 + endAnimation); // 32
    	glVertex2i(245+movex, 45 + endAnimation); // 33
    	glVertex2i(245+movex, 25 + endAnimation); // 34
    glEnd();

  	movex += dir;
}

void drawLives(){
	glColor3f(0,0,.3);
	
	if(lives >= 1){
		glBegin(GL_POLYGON);
			glVertex2i(5, 550);
			glVertex2i(10, 550);
			glVertex2i(10, 580);
			glVertex2i(5, 580);
			glVertex2i(5, 550);
		glEnd();
	}	

	if(lives >= 2){
		glBegin(GL_POLYGON);
			glVertex2i(15, 550);
			glVertex2i(20, 550);
			glVertex2i(20, 580);
			glVertex2i(15, 580);
			glVertex2i(15, 550);
		glEnd();
	}

	if(lives == 3){
		glBegin(GL_POLYGON);
			glVertex2i(25, 550);
			glVertex2i(30, 550);
			glVertex2i(30, 580);
			glVertex2i(25, 580);
			glVertex2i(25, 550);
		glEnd();
	}
}

void drawEnemy(){

	glColor3f(0,.1,.85);
	glBegin(GL_POLYGON);
    	glVertex2i(enemyX, (25 + enemyY) + enemyMove); // 1
    	glVertex2i(20+enemyX, (25 + enemyY) + enemyMove); // 2
    	glVertex2i(20+enemyX, (85 + enemyY) + enemyMove); // 19
    	glVertex2i(10+enemyX, (95 + enemyY) + enemyMove); // 20
    	glVertex2i(enemyX, (85 + enemyY) + enemyMove); // 21
    	glVertex2i(enemyX, (25 + enemyY) + enemyMove); // 1
    glEnd();

    // ligação direita traseira
    glColor3f(.8,.8,.8);
    glBegin(GL_POLYGON);
    	glVertex2i(20+enemyX, (30 + enemyY) + enemyMove); // 3
    	glVertex2i(25+enemyX, (30 + enemyY) + enemyMove); // 4
    	glVertex2i(25+enemyX, (40 + enemyY) + enemyMove); // 9
		glVertex2i(20+enemyX, (40 + enemyY) + enemyMove); // 10
		glVertex2i(20+enemyX, (30 + enemyY) + enemyMove); // 3
	glEnd();

	glColor3f(.3,.3,.3);
	// roda direita traseira
	glBegin(GL_POLYGON);
    	glVertex2i(25+enemyX, (25 + enemyY) + enemyMove); // 5
    	glVertex2i(35+enemyX, (25 + enemyY) + enemyMove); // 6
    	glVertex2i(35+enemyX, (45 + enemyY) + enemyMove); // 7
    	glVertex2i(25+enemyX, (45 + enemyY) + enemyMove); // 8
    	glVertex2i(25+enemyX, (25 + enemyY) + enemyMove); // 5
    glEnd();

    glColor3f(.8,.8,.8);
    // ligação direita dianteira
    glBegin(GL_POLYGON);	
    	glVertex2i(20+enemyX, (60 + enemyY) + enemyMove); // 11
    	glVertex2i(25+enemyX, (60 + enemyY) + enemyMove); // 12
    	glVertex2i(25+enemyX, (70 + enemyY) + enemyMove); // 17
    	glVertex2i(20+enemyX, (70 + enemyY) + enemyMove); // 18
    	glVertex2i(20+enemyX, (60 + enemyY) + enemyMove); // 11
    glEnd();

    glColor3f(.3,.3,.3);
    // roda direita dianteira
    glBegin(GL_POLYGON);	
    	glVertex2i(25+enemyX, (55 + enemyY) + enemyMove); // 13
    	glVertex2i(35+enemyX, (55 + enemyY) + enemyMove); // 14
    	glVertex2i(35+enemyX, (75 + enemyY) + enemyMove); // 15
    	glVertex2i(25+enemyX, (75 + enemyY) + enemyMove); // 16
    	glVertex2i(25+enemyX, (55 + enemyY) + enemyMove); // 13
    glEnd();

    glColor3f(.8,.8,.8);
    //ligação esquerda dianteira
    glBegin(GL_POLYGON);
    	glVertex2i(enemyX, (60 + enemyY) + enemyMove); // 28
    	glVertex2i(enemyX-5, (60 + enemyY) + enemyMove); // 29
    	glVertex2i(enemyX-5, (70 + enemyY) + enemyMove); // 22
    	glVertex2i(enemyX, (70 + enemyY) + enemyMove); // 23
    	glVertex2i(enemyX, (60 + enemyY) + enemyMove); // 28
    glEnd();

    glColor3f(.3,.3,.3);
    //roda esquerda dianteira
    glBegin(GL_POLYGON);
    	glVertex2i(enemyX-5, (55 + enemyY) + enemyMove); // 26
    	glVertex2i(enemyX-15, (55 + enemyY) + enemyMove); // 27
    	glVertex2i(enemyX-15, (75 + enemyY) + enemyMove); // 24
    	glVertex2i(enemyX-5, (75 + enemyY) + enemyMove); // 25
    	glVertex2i(enemyX-5, (55 + enemyY) + enemyMove); // 26
    glEnd();

    glColor3f(.8,.8,.8);
    //ligação esquerda traseira
    glBegin(GL_POLYGON);
    	glVertex2i(enemyX, (30 + enemyY) + enemyMove); // 36
    	glVertex2i(enemyX-5, (30 + enemyY) + enemyMove); // 37
    	glVertex2i(enemyX-5, (40 + enemyY) + enemyMove); // 30
    	glVertex2i(enemyX-0, (40 + enemyY) + enemyMove); // 31
    	glVertex2i(enemyX-0, (30 + enemyY) + enemyMove); // 36
    glEnd();

    glColor3f(.3,.3,.3);
    //roda esquerda traseira
    glBegin(GL_POLYGON);
    	glVertex2i(enemyX-5, (25 + enemyY) + enemyMove); // 34
    	glVertex2i(enemyX-15, (25 + enemyY) + enemyMove); // 35
    	glVertex2i(enemyX-15, (45 + enemyY) + enemyMove); // 32
    	glVertex2i(enemyX-5, (45 + enemyY) + enemyMove); // 33
    	glVertex2i(enemyX-5, (25 + enemyY) + enemyMove); // 34
    glEnd();

  	if(enemyMove < -700){
  		enemyMove = -1;
  		enemyX = rand() % (max - min) + min;
  	} else if(isColliding || playerLeft < 150 || playerRight > 450){
  		enemyMove = -1;
  		enemyX = rand() % (max - min) + min;
  		lives--;
  		getchar();
  		movex = 0;
  		isColliding = false;
  	}
  	else
  		enemyMove += -1;

}

void checkCollision(){
	if(enemyX - 15 < playerRight && enemyX + 35 > playerLeft && enemyMove <= -525){
		isColliding = true;
	}
}

void drawMap(){

	//line
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    	glVertex2i(525, 30); // 34
    	glVertex2i(527, 30); // 35
    	glVertex2i(527, 550); // 32
    	glVertex2i(525, 550); // 33
    	glVertex2i(525, 30); // 34
    glEnd();

    //endpoint
    glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    	glVertex2i(520, 550); // 34
    	glVertex2i(532, 550); // 35
    	glVertex2i(532, 553); // 32
    	glVertex2i(520, 553); // 33
    	glVertex2i(520, 550); // 34
    glEnd();

    //carPos
    glColor3f(.9,0,0);
	glBegin(GL_POLYGON);
    	glVertex2f(520, carMapPos); // 34
    	glVertex2f(532, carMapPos); // 35
    	glVertex2f(532, carMapPos+10); // 32
    	glVertex2f(520, carMapPos+10); // 33
    	glVertex2f(520, carMapPos); // 34
    glEnd();

    if(carMapPos < 550){
    	carMapPos+= 0.05;
    }

}

void drawEndLine(){
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
    	glVertex2f(150, endLine); // 34
    	glVertex2f(450, endLine); // 35
    	glVertex2f(450, endLine+25); // 32
    	glVertex2f(150, endLine+25); // 33
    	glVertex2f(150, endLine); // 34
    glEnd();

    if(endLine >= 500)
    	endLine -= 1;
}

void displayText(float x, float y, int r, int g, int b, const char *string ) {
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for(int i = 0; i < j; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

  	drawGrass();
  	drawPlayer();
  	drawLives();
  	drawMap();

	if(carMapPos > 540)
  		drawEndLine();
  	else
  		drawEnemy();

  	if(endLine < 500){
  		endAnimation++;
  	}

  	if(endAnimation > 20){
  		displayText(200, 300, 1, 1, 1, end);
  	}

  
  glFlush();

  checkCollision();

  if(lives == 0){
  	exit(0);
  }

  glutPostRedisplay();
  glutSwapBuffers();
}

void keyDown(unsigned char key, int xmouse, int ymouse){
	if(key == 'a')
		dir = -1;

    if(key == 'd')
		dir = 1;

  glutPostRedisplay();
    
}

void keyUp(unsigned char key, int xmouse, int ymouse){
	if(key == 'a')
		dir = 0;

    if(key == 'd')
		dir = 0;
}

void windowSize(GLsizei w, GLsizei h) 
{ 
  if(h == 0)
    h = 1;
  
  glViewport(0, 0, w, h);
     
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
     
  if (w <= h)
    gluOrtho2D(0, TAMJANELA, 0, TAMJANELA*h/w);
  else
    gluOrtho2D(0, TAMJANELA*w/h, 0, TAMJANELA);
}

int main(int argc, char** argv){
	strcpy(end, "YOU WIN!");
	srand(time(NULL));
  	glutInit(&argc, argv); 
  	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize(TAMJANELA, TAMJANELA);
  	glutInitWindowPosition(10,10);
  	glutCreateWindow("OpenGL - Animacao 2D");
  	glutDisplayFunc(draw);
  	glutReshapeFunc(windowSize);
  	glutKeyboardFunc(keyDown);
  	glutKeyboardUpFunc(keyUp);
  	glutIgnoreKeyRepeat(1);
  	Start();
  	glutMainLoop();
  	return 0;
}
