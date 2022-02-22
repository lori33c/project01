#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../cpputils/graphics/image.h"
#include "../cppaudit/gtest_ext.h"

class Image : public ::testing::Test {
protected:
  void SetUp() override {
    std::string randnum = std::to_string(rand());
    player_filename = "player_" + randnum + ".bmp";
    opponent_filename = "opponent_" + randnum + ".bmp";
    player_projectile_filename = "p_projectile_" + randnum + ".bmp";
    opponent_projectile_filename = "o_projectile_" + randnum + ".bmp";
  }

  void TearDown() override {
    remove(player_filename.c_str());
    remove(opponent_filename.c_str());
    remove(player_projectile_filename.c_str());
    remove(opponent_projectile_filename.c_str());
  }

  std::string player_filename;
  std::string opponent_filename;
  std::string player_projectile_filename;
  std::string opponent_projectile_filename;
};

TEST_F(Image, ScreenOutput) {
  std::string input = player_filename + "\n" + opponent_filename + "\n" +
                      player_projectile_filename + "\n" +
                      opponent_projectile_filename + "\n";
  std::string output = "Please provide player image filename: "
                       "Please provide opponent image filename: "
                       "Please provide player projectile image filename: "
                       "Please provide opponent projectile image filename: ";
  ASSERT_EXECEQ("main", input, output)
      << "Please make sure to use the sentences"
         " exactly as specified in the instructions.";
}

TEST_F(Image, Player) {
  std::string input = player_filename + "\n" + opponent_filename + "\n" +
                      player_projectile_filename + "\n" +
                      opponent_projectile_filename + "\n";
  std::string output = "Please provide player image filename: "
                       "Please provide opponent image filename: "
                       "Please provide player projectile image filename: "
                       "Please provide opponent projectile image filename: ";
  ASSERT_EXECEQ("main", input, output)
      << "Please make sure to use the sentences"
         " exactly as specified in the instructions.";
  graphics::Image the_image;
  bool image_loaded = the_image.Load(player_filename);
  ASSERT_TRUE(image_loaded)
      << "Your program should create a file whose filename matches "
         "the user's input.";
  bool has_drawing = false;
  for (int i = 0; i < the_image.GetHeight(); i++) {
    for (int j = 0; j < the_image.GetWidth(); j++) {
      if (the_image.GetColor(i, j) != graphics::Color(255, 255, 255)) {
        has_drawing = true;
        break;
      }
    }
    if (has_drawing) {
      break;
    }
  }
  ASSERT_TRUE(has_drawing)
      << "Your program should draw a character for the player.";
}

TEST_F(Image, Opponent) {
  std::string input = player_filename + "\n" + opponent_filename + "\n" +
                      player_projectile_filename + "\n" +
                      opponent_projectile_filename + "\n";
  std::string output = "Please provide player image filename: "
                       "Please provide opponent image filename: "
                       "Please provide player projectile image filename: "
                       "Please provide opponent projectile image filename: ";
  ASSERT_EXECEQ("main", input, output)
      << "Please make sure to use the sentences"
         " exactly as specified in the instructions.";
  graphics::Image the_image;
  bool image_loaded = the_image.Load(opponent_filename);
  ASSERT_TRUE(image_loaded)
      << "Your program should create a file whose filename matches "
         "the user's input.";
  bool has_drawing = false;
  for (int i = 0; i < the_image.GetHeight(); i++) {
    for (int j = 0; j < the_image.GetWidth(); j++) {
      if (the_image.GetColor(i, j) != graphics::Color(255, 255, 255)) {
        has_drawing = true;
        break;
      }
    }
    if (has_drawing) {
      break;
    }
  }
  ASSERT_TRUE(has_drawing)
      << "Your program should draw a character for the opponent.";
}

TEST_F(Image, PlayerProjectile) {
  std::string input = player_filename + "\n" + opponent_filename + "\n" +
                      player_projectile_filename + "\n" +
                      opponent_projectile_filename + "\n";
  std::string output = "Please provide player image filename: "
                       "Please provide opponent image filename: "
                       "Please provide player projectile image filename: "
                       "Please provide opponent projectile image filename: ";
  ASSERT_EXECEQ("main", input, output)
      << "Please make sure to use the sentences"
         " exactly as specified in the instructions.";
  graphics::Image the_image;
  bool image_loaded = the_image.Load(player_projectile_filename);
  ASSERT_TRUE(image_loaded)
      << "Your program should create a file whose filename matches "
         "the user's input.";
  bool has_drawing = false;
  for (int i = 0; i < the_image.GetHeight(); i++) {
    for (int j = 0; j < the_image.GetWidth(); j++) {
      if (the_image.GetColor(i, j) != graphics::Color(255, 255, 255)) {
        has_drawing = true;
        break;
      }
    }
    if (has_drawing) {
      break;
    }
  }
  ASSERT_TRUE(has_drawing)
      << "Your program should draw a projectile for the player.";
}

TEST_F(Image, OpponentProjectile) {
  std::string input = player_filename + "\n" + opponent_filename + "\n" +
                      player_projectile_filename + "\n" +
                      opponent_projectile_filename + "\n";
  std::string output = "Please provide player image filename: "
                       "Please provide opponent image filename: "
                       "Please provide player projectile image filename: "
                       "Please provide opponent projectile image filename: ";
  ASSERT_EXECEQ("main", input, output)
      << "Please make sure to use the sentences"
         " exactly as specified in the instructions.";
  graphics::Image the_image;
  bool image_loaded = the_image.Load(opponent_projectile_filename);
  ASSERT_TRUE(image_loaded)
      << "Your program should create a file whose filename matches "
         "the user's input.";
  bool has_drawing = false;
  for (int i = 0; i < the_image.GetHeight(); i++) {
    for (int j = 0; j < the_image.GetWidth(); j++) {
      if (the_image.GetColor(i, j) != graphics::Color(255, 255, 255)) {
        has_drawing = true;
        break;
      }
    }
    if (has_drawing) {
      break;
    }
  }
  ASSERT_TRUE(has_drawing)
      << "Your program should draw a projectile for the opponent.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
