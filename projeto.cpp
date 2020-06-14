//g++ -o aula1 aula1.cpp -lSDLmain -lSDL -lGL 

#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_WM_SetCaption("Cdódigo de Sênior", NULL);

	SDL_SetVideoMode(600,400,32, SDL_OPENGL);

	glClearColor(1,1,1,1);

	glViewport(0,0,600,400);

	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);

	bool exec = true;
	SDL_Event event;

	float personX = 300;
	float personY = 350;
	float personComp = 50;
	float personAlt = 30; 
	bool esq = false, dir = false, up = false, down = false;
	while(exec)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				exec = false;
			}
			if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
			{
				exec = false;
			}
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					esq = true;
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					dir = true;
				}
				if(event.key.keysym.sym == SDLK_UP)
				{
					up = true;
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					down = true;
				}
			}
			else if(event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					esq =false ;
				}
				if(event.key.keysym.sym == SDLK_RIGHT)
				{
					dir = false;
				}
				if(event.key.keysym.sym == SDLK_UP)
				{
					up = false;
				}
				if(event.key.keysym.sym == SDLK_DOWN)
				{
					down = false;
				}
			}
		}
		
		if(esq)
		{
			personX -= 8;
		}
		if(dir)
		{
			personX += 8;	
		}
		if(up)
		{
			personY -= 8;
		}
		if(down)
		{
			personY += 8;
		}
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();

		glOrtho(0, 600, 400, 0, -1, 1);

		glColor4ub(255,0,0,255);

		glBegin(GL_QUADS);

		glVertex2f(personX, personY);
		glVertex2f(personX + personComp, personY);
		glVertex2f(personX + personComp, personY + personAlt);
		glVertex2f(personX, personY + personAlt);
		glEnd();
		glPopMatrix();
		SDL_GL_SwapBuffers();
	}

	
	SDL_Quit();

	return 0;
}
