#include "painter.h"

/***
    Args: color (SDL_Color): color value

    Returns:
        None
***/
void Painter::setColor(SDL_Color color)
{
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}


/***
    Args: numPixel (int): number of pixel for jumping forward

    Returns:
        None
***/
void Painter::jumpForward(int numPixel)
{
    x += numPixel * cos(angle * M_PI / 180.0);
    y += numPixel * sin(angle * M_PI / 180.0);
}


/***
    Args: numPixel (int): number of pixel for jumping backward

    Returns:
        None
***/
void Painter::jumpBackward(int numPixel)
{
    x -= numPixel * cos(angle * M_PI / 180.0);
    y -= numPixel * sin(angle * M_PI / 180.0);
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnLeft(double degree)
{
    angle -= degree;
    if (angle < 0) {
        angle += 360;
    }
}


/***
    Args: degree (double): the value of rotation angle

    Returns:
        None
***/
void Painter::turnRight(double degree)
{
    angle += degree;
    if (angle >= 360) {
        angle -= 360;
    }
}

/***
    Args:
        None
    Returns:
        None
***/
void Painter::randomColor()
{
    SDL_Color randColor = {
        static_cast<Uint8>(rand() % 256),
        static_cast<Uint8>(rand() % 256),
        static_cast<Uint8>(rand() % 256),
        255
    };
    setColor(randColor);

}


/***
Part of code that not need to be implemented
***/
void Painter::clearWithBgColor(SDL_Color bgColor)
{
    SDL_Color curColor = color;
    setColor(bgColor);
	SDL_RenderClear(renderer);
    setColor(curColor);
}


Painter::Painter(SDL_Window* window, SDL_Renderer *renderer)
{
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0) {
        SDL_GetWindowSize(window, &width, &height);
    }
    this->renderer = renderer;
    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}


void Painter::createCircle(int radius)
{
    double rad = (angle / 180) * M_PI;
    int centerX = x + (int) (cos(rad) * (double) radius);;
    int centerY = y - (int) (sin(rad) * (double) radius);;

    int dx = radius;
    int dy = 0;
    int err = 0;

    while (dx >= dy)
    {
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY + dx);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY + dy);
        SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
        SDL_RenderDrawPoint(renderer, centerX - dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dy, centerY - dx);
        SDL_RenderDrawPoint(renderer, centerX + dx, centerY - dy);

        if (err <= 0)
        {
            dy += 1;
            err += 2*dy + 1;
        }
        if (err > 0)
        {
            dx -= 1;
            err -= 2*dx + 1;
        }
    }
}



void Painter::createParallelogram(int size)
{
	for (int i = 0; i < 2; ++i) {
        moveForward(size);
        turnLeft(60);
        moveForward(size);
        turnLeft(120);
    }
}



void Painter::createSquare(int size)
{
	for (int i = 0; i < 4; ++i) {
        moveForward(size);
	    turnLeft(90);
    }
}


void Painter::moveForward(int numPixel)
{
    int preX = x, preY = y;
    jumpForward(numPixel);
    SDL_RenderDrawLine(renderer, preX, preY, x, y);
}


void Painter::moveBackward(int numPixel)
{
    moveForward(-numPixel);
}

