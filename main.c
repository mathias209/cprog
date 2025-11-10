#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#define WIDTH 400
#define HEIGHT 400
#define TITLE "Balls and their admirers"
#define BALL_COUNT 100
#define FPS 60
#define VEL_MAX 5
#define RADIUS_MAX 20
#define RADIUS_MIN 5

#define _countof(array) (sizeof(array) / sizeof(array[0]))

Color COLORS[] = {
    LIGHTGRAY, GRAY,   DARKGRAY, YELLOW,     GOLD,      ORANGE,  PINK,
    RED,       MAROON, GREEN,    LIME,       DARKGREEN, SKYBLUE, BLUE,
    DARKBLUE,  PURPLE, VIOLET,   DARKPURPLE, BEIGE,     BROWN,   DARKBROWN,
};

// Definition of Ball
// Ball stores state and other properties
typedef struct Ball {
    int id;
    int posx;
    int posy;
    int velx;
    int vely;
    int radius;
    Color color;
    struct Ball* follows;
} Ball;

Ball balls[BALL_COUNT];

int rannum(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

// Initializes a ball with random values
Ball *init_ball_random(Ball *p, int id) {
  // Randomly initialize state and properties
    p->color = COLORS[rannum(0, 20)];
    p->posx = rannum(0, WIDTH - 1);
    p->posy = rannum(0, HEIGHT - 1);
    p->velx = rannum(1, VEL_MAX - 1);
    p->vely = rannum(1, VEL_MAX - 1);
    p->radius = rannum(RADIUS_MIN, RADIUS_MAX);

    p->id = id;

  // Find a leading ball other than the initialized ball itself.
  Ball *leader; // Represents the leading ball that this ball will follow
  leader = &balls[rannum(0, BALL_COUNT - 1)];
  p->follows=leader;

  return p;
}


// Initialize all `balls`
void init_balls_random() {
    srand(time(NULL));
    for(int i = 0; i < BALL_COUNT; i++)
	init_ball_random(&balls[i], i);
}

Ball *draw_ball(Ball *p) {
  DrawCircle(p->posx, p->posy, p->radius, p->color);
  return p;
}

// Updates the positions of balls according to their velocities
Ball *update_pos(Ball *p) {
  p->posx = (WIDTH + p->posx + p->velx) %
            WIDTH; // `WIDTH +` because C uses truncated division
  p->posy = (HEIGHT + p->posy + p->vely) % HEIGHT;
  return p;
}

// Updates the velocity of a ball so that it follows the leading ball
Ball *update_vel_for_following(Ball *p) {
  int errx = p->follows->posx - p->posx;
  int erry = p->follows->posy - p->posy;
  p->velx = errx > 0 ? 1 : -1;
  p->vely = erry > 0 ? 1 : -1;
  return p;
}

// Update all elements
void update_elements() {
    for (size_t i = 0; i < _countof (balls); ++i) {
    draw_ball(update_pos(update_vel_for_following(&balls[i])));
  }
}

int main() {
  InitWindow(WIDTH, HEIGHT, TITLE);
  SetTargetFPS(FPS);

  init_balls_random();


  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    update_elements();
    ClearBackground(WHITE);
    EndDrawing();
  }
}
