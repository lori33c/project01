# include <iostream>
# include <string>
# include <vector>
# include "cpputils/graphics/image.h"

void DrawPlayer(std::string player_image_file) {
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
  player_image.SaveImageBmp(player_image_file);
}

void DrawOpponent(std::string opponent_image_file) {
  // 2. Create Opponent image (50 x 50 pixel)
  // 1. Create Opponent image (50 x 50 pixel)
  const int Opponent_size = 50;
  graphics::Image Opponent_image(Opponent_size, Opponent_size);

  // Draws the face
  Opponent_image.DrawCircle(Opponent_size/2, Opponent_size/2, Opponent_size/3, 0, 0, 0);
  Opponent_image.DrawPolygon({25, 20, 10, 5, 10, 30}, 0, 0, 0);
  Opponent_image.DrawPolygon({25, 20, 40, 5, 40, 30}, 0, 0, 0);

  // Draw the eyes
  Opponent_image.DrawCircle(18, 20, 2, 255, 0, 0);
  Opponent_image.DrawCircle(32, 20, 2, 255, 0, 0);

  // Draw mouth
  Opponent_image.DrawPolygon({25, 25, 20, 32, 30, 32}, 243, 0, 0);

  // Saves the Player image
  Opponent_image.SaveImageBmp(opponent_image_file);
}

void DrawPlayerProjectile(std::string player_projectile_file) {
  // 3. Create Player Projectile image (5 x 5 pixel)
  const int play_size = 5;
	graphics::Image play_image(play_size, play_size);
	play_image.DrawCircle(play_size/2, play_size/2, play_size/2, 0, 0, 255);
	play_image.SaveImageBmp(player_projectile_file);
}

void DrawOpponentProjectile(std::string opponent_projectile_file) {
  // 4. Create Opponent Projectile image (5 x 5 pixel)
  const int Opp_size = 5;
	graphics::Image Opp_image(Opp_size, Opp_size);
	Opp_image.DrawCircle(Opp_size/2, Opp_size/2, Opp_size/2, 255, 0, 0);
	Opp_image.SaveImageBmp(opponent_projectile_file);
}

int main() {
  // Input Filenames
  std::string player_image_file;
  std::string opponent_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;

  // Prompt user to input file names
  std::cout << "Please provide player image filename: ";
  std::cin >> player_image_file;
  std::cout << "Please provide opponent image filename: ";
  std::cin >> opponent_image_file;
  std::cout << "Please provide player projectile image filename: ";
  std::cin >> player_projectile_file;
  std::cout << "Please provide opponent projectile image filename: ";
  std::cin >> opponent_projectile_file;

  DrawPlayer(player_image_file);
  DrawOpponent(opponent_image_file);
  DrawPlayerProjectile(player_projectile_file);
  DrawOpponentProjectile(opponent_projectile_file);

  return 0;
}
