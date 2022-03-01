# include <iostream>
# include <string>
# include "graphics/image.h"

int main() {
  std::string player_image_file;
  std::string opponent_image_file;
  std::string player_projectile_file;
  std::string opponent_projectile_file;
  
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
