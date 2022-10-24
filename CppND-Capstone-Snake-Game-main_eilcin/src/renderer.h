#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include <thread>
#include <future>
#include <chrono>
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food ,std::vector<SDL_Point> const &ObstaclePos);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  
  std::mutex _mutex;
  void RenderSnake(Snake const snake);
  void RenderFood(SDL_Point const &food);
  void RenderObstacle(std::vector<SDL_Point> const &ObstaclePos);
};

#endif