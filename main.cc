# include <iostream>
# include <string>
# include <vector>
# include "cpputils/graphics/image.h"

void DrawPlayer() {
  // 1. Create Player image (50 x 50 pixel)
  const int player_size = 50;
  graphics::Image player_image(player_size, player_size);

  // Draws the face
  player_image.DrawCircle(player_size/2, player_size/2, player_size/3, 167, 133, 106);
  player_image.DrawPolygon({25, 20, 10, 5, 10, 30}, 167, 133, 106);
  player_image.DrawPolygon({25, 20, 40, 5, 40, 30}, 167, 133, 106);

  // Draw the eyes
  player_image.DrawCircle(18, 20, 2, 0, 0, 0);
  player_image.DrawCircle(32, 20, 2, 0, 0, 0);

  // Draw mouth
  player_image.DrawPolygon({25, 25, 20, 32, 30, 32}, 243, 82, 120);

  // Draw nose
  player_image.DrawCircle(25, 25 , 1, 0, 0, 0);

  // Saves the Player image
  player_image.SaveImageBmp("player.bmp");
}

void DrawOpponent() {
  // 2. Create Opponent image (50 x 50 pixel)
}

void DrawPlayerProjectile() {
  // 3. Create Player Projectile image (5 x 5 pixel)
}

void DrawOpponentProjectile() {
  // 4. Create Opponent Projectile image (5 x 5 pixel)
}

int main() {
  // Input Filenames
  std::string player_image_file;
  std::string opponent_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;

  // Create Player image
  DrawPlayer();
  
  // 2. Create Opponent image (50 x 50 pixel)
  // DrawOpponent();

  // 3. Create Player Projectile image (5 x 5 pixel)
  // DrawPlayerProjectile();

  // 4. Create Opponent Projectile image (5 x 5 pixel)
  // DrawOpponentProjectile();

  // Prompt user to input file names
  std::cout << "Please provide player image filename: ";
  std::cin >> player_image_file;
  std::cout << "Please provide opponent image filename: ";
  std::cin >> opponent_image_file;
  std::cout << "Please provide player projectile filename: ";
  std::cin >> player_projectile_file;
  std::cout << "Please provide opponent projectile filename: ";
  std::cin >> opponent_projectile_file;


  return 0;
}
