#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../cpputils/graphics/image.h"
#include "../cppaudit/gtest_ext.h"
#include "../../player.h"
#include "../../opponent.h"

// Opponent unittests

TEST(Opponent, DefaultConstructor) {
  Opponent my_opponent;
  ASSERT_EQ(my_opponent.GetX(), 0) << "Opponent objects' default x location should be set to 0.";
  ASSERT_EQ(my_opponent.GetY(), 0) << "Opponent objects' default y location should be set to 0.";
  ASSERT_NE(my_opponent.GetHeight(), 0) << "Opponent height should not be 0.";
  ASSERT_NE(my_opponent.GetWidth(), 0) << "Opponent width should not be 0.";
}

TEST(Opponent, ParemterizedConstructor) {
  Opponent my_opponent(5, 8);
  ASSERT_EQ(my_opponent.GetX(), 5) << "Opponent objects' x location should be set to the first parameter.";
  ASSERT_EQ(my_opponent.GetY(), 8) << "Opponent objects' y location should be set to the second parameter.";
  ASSERT_NE(my_opponent.GetHeight(), 0) << "Opponent height should not be 0.";
  ASSERT_NE(my_opponent.GetWidth(), 0) << "Opponent width should not be 0.";
}

void OpponentDraw() {
  Opponent my_opponent(10, 10);
  int width = my_opponent.GetWidth();
  int height = my_opponent.GetHeight();
  graphics::Image test_screen(800, 600);
  ASSERT_DURATION_LE(3, {
    my_opponent.Draw(test_screen);
  })
  
  bool has_drawing = false;
  bool has_extraneous_drawing = false;

  graphics::Color white(255, 255, 255);
  for (int y = 0; y < test_screen.GetHeight(); y++) {
    for (int x = 0; x < test_screen.GetWidth(); x++) {
      if (test_screen.GetColor(x, y) != white) {
        if (x >= 10 && x <= 10 + width && y >= 10 && y <= 10 + height) {
          has_drawing = true;
        } else {
          has_extraneous_drawing = true;
        }
      }
    }
  }
  ASSERT_TRUE(has_drawing) << "The Opponent object's Draw method should draw an image to the given image object.";
  ASSERT_FALSE(has_extraneous_drawing) << "The Opponent object's Draw method should only draw inside it's boundaries.";  
}

TEST(Opponent, Draw) {
  ASSERT_EXIT((OpponentDraw(),exit(0)),::testing::ExitedWithCode(0),".*")
        << "    Should not crash or infinitely loop.";
    OpponentDraw();
}

// OpponentProjectile Unittests

TEST(OpponentProjectile, DefaultConstructor) {
  OpponentProjectile my_opponentprojectile;
  ASSERT_EQ(my_opponentprojectile.GetX(), 0) << "Opponent objects' default x location should be set to 0.";
  ASSERT_EQ(my_opponentprojectile.GetY(), 0) << "Opponent objects' default y location should be set to 0.";
  ASSERT_NE(my_opponentprojectile.GetHeight(), 0) << "Opponent height should not be 0.";
  ASSERT_NE(my_opponentprojectile.GetWidth(), 0) << "Opponent width should not be 0.";
}

TEST(OpponentProjectile, ParemterizedConstructor) {
  OpponentProjectile my_opponentprojectile(5, 8);
  ASSERT_EQ(my_opponentprojectile.GetX(), 5) << "Opponent objects' x location should be set to the first parameter.";
  ASSERT_EQ(my_opponentprojectile.GetY(), 8) << "Opponent objects' y location should be set to the second parameter.";
  ASSERT_NE(my_opponentprojectile.GetHeight(), 0) << "Opponent height should not be 0.";
  ASSERT_NE(my_opponentprojectile.GetWidth(), 0) << "Opponent width should not be 0.";
}

void OpponentProjectileDraw() {
  OpponentProjectile my_opponentprojectile(10, 10);
  int width = my_opponentprojectile.GetWidth();
  int height = my_opponentprojectile.GetHeight();
  graphics::Image test_screen(800, 600);
  ASSERT_DURATION_LE(3, {
    my_opponentprojectile.Draw(test_screen);    
  })

  bool has_drawing = false;
  bool has_extraneous_drawing = false;

  graphics::Color white(255, 255, 255);
  for (int y = 0; y < test_screen.GetHeight(); y++) {
    for (int x = 0; x < test_screen.GetWidth(); x++) {
      if (test_screen.GetColor(x, y) != white) {
        if (x >= 10 && x <= 10 + width && y >= 10 && y <= 10 + height) {
          has_drawing = true;
        } else {
          has_extraneous_drawing = true;
        }
      }
    }
  }
  ASSERT_TRUE(has_drawing) << "The OpponentProjectile object's Draw method should draw an image to the given image object.";
  ASSERT_FALSE(has_extraneous_drawing) << "The OpponentProjectile object's Draw method should only draw inside it's boundaries.";
}

TEST(OpponentProjectile, Draw) {
  ASSERT_EXIT((OpponentProjectileDraw(),exit(0)),::testing::ExitedWithCode(0),".*")
      << "    Should not crash or infinitely loop";
  OpponentProjectileDraw();
}

// Player Unittests

TEST(Player, DefaultConstructor) {
  Player my_player;
  ASSERT_EQ(my_player.GetX(), 0) << "Player objects' default x location should be set to 0.";
  ASSERT_EQ(my_player.GetY(), 0) << "Player objects' default y location should be set to 0.";
  ASSERT_NE(my_player.GetHeight(), 0) << "Player height should not be 0.";
  ASSERT_NE(my_player.GetWidth(), 0) << "Player width should not be 0.";
}

TEST(Player, ParemterizedConstructor) {
  Player my_player(5, 8);
  ASSERT_EQ(my_player.GetX(), 5) << "Player objects' x location should be set to the first parameter.";
  ASSERT_EQ(my_player.GetY(), 8) << "Player objects' y location should be set to the second parameter.";
  ASSERT_NE(my_player.GetHeight(), 0) << "Player height should not be 0.";
  ASSERT_NE(my_player.GetWidth(), 0) << "Player width should not be 0.";
}

void PlayerDraw() {
  Player my_player(10, 10);
  int width = my_player.GetWidth();
  int height = my_player.GetHeight();
  graphics::Image test_screen(800, 600);
  ASSERT_DURATION_LE(3, {
    my_player.Draw(test_screen);  
  })
  
  bool has_drawing = false;
  bool has_extraneous_drawing = false;

  graphics::Color white(255, 255, 255);
  for (int y = 0; y < test_screen.GetHeight(); y++) {
    for (int x = 0; x < test_screen.GetWidth(); x++) {
      if (test_screen.GetColor(x, y) != white) {
        if (x >= 10 && x <= 10 + width && y >= 10 && y <= 10 + height) {
          has_drawing = true;
        } else {
          has_extraneous_drawing = true;
        }
      }
    }
  }
  ASSERT_TRUE(has_drawing) << "The Player object's Draw method should draw an image to the given image object.";
  ASSERT_FALSE(has_extraneous_drawing) << "The Player object's Draw method should only draw inside it's boundaries.";   
}

TEST(Player, Draw) {
  ASSERT_EXIT((PlayerDraw(),exit(0)),::testing::ExitedWithCode(0),".*")
        << "    Should not crash or infinitely loop.";
  PlayerDraw();
}

TEST(Player, IntersectsWithOpponent) {
  Player my_player(40, 100);
  
  Opponent my_left_opponent;
  my_left_opponent.SetX(40 - (my_left_opponent.GetWidth() - 1));
  my_left_opponent.SetY(100);
  ASSERT_TRUE(my_player.IntersectsWith(my_left_opponent)) << "A Player object must check if an Opponent intersects with it's left side.";

  Opponent my_right_opponent;
  my_right_opponent.SetX(40 + my_player.GetWidth() - 1);
  my_right_opponent.SetY(100);
  ASSERT_TRUE(my_player.IntersectsWith(my_right_opponent)) << "A Player object must check if an Opponent intersects with it's right side.";

  Opponent my_top_opponent;
  my_top_opponent.SetX(40);
  my_top_opponent.SetY(100 - (my_top_opponent.GetHeight() - 1));
  ASSERT_TRUE(my_player.IntersectsWith(my_top_opponent)) << "A Player object must check if an Opponent intersects with it's top side.";

  Opponent my_bottom_opponent;
  my_bottom_opponent.SetX(40);
  my_bottom_opponent.SetY(100 + my_player.GetHeight() - 1);
  ASSERT_TRUE(my_player.IntersectsWith(my_bottom_opponent)) << "A Player object must check if an Opponent intersects with it's top side.";
}

TEST(Player, IntersectsWithOpponentProjectile) {
  Player my_player(50, 110);
  
  Opponent my_left_opponentprojectile;
  my_left_opponentprojectile.SetX(50 - (my_left_opponentprojectile.GetWidth() - 1));
  my_left_opponentprojectile.SetY(110);
  ASSERT_TRUE(my_player.IntersectsWith(my_left_opponentprojectile)) << "A Player object must check if an OpponentProjectile intersects with it's left side.";

  Opponent my_right_opponentprojectile;
  my_right_opponentprojectile.SetX(50 + my_player.GetWidth() - 1);
  my_right_opponentprojectile.SetY(110);
  ASSERT_TRUE(my_player.IntersectsWith(my_right_opponentprojectile)) << "A Player object must check if an OpponentProjectile intersects with it's right side.";

  Opponent my_top_opponentprojectile;
  my_top_opponentprojectile.SetX(50);
  my_top_opponentprojectile.SetY(110 - (my_top_opponentprojectile.GetHeight() - 1));
  ASSERT_TRUE(my_player.IntersectsWith(my_top_opponentprojectile)) << "A Player object must check if an OpponentProjectile intersects with it's top side.";

  Opponent my_bottom_opponentprojectile;
  my_bottom_opponentprojectile.SetX(50);
  my_bottom_opponentprojectile.SetY(110 + my_player.GetHeight() - 1);
  ASSERT_TRUE(my_player.IntersectsWith(my_bottom_opponentprojectile)) << "A Player object must check if an OpponentProjectile intersects with it's top side.";
}

// PlayerProjectile Unittests

TEST(PlayerProjectile, DefaultConstructor) {
  PlayerProjectile my_playerprojectile;
  ASSERT_EQ(my_playerprojectile.GetX(), 0) << "PlayerProjectile objects' default x location should be set to 0.";
  ASSERT_EQ(my_playerprojectile.GetY(), 0) << "PlayerProjectile objects' default y location should be set to 0.";
  ASSERT_NE(my_playerprojectile.GetHeight(), 0) << "PlayerProjectile height should not be 0.";
  ASSERT_NE(my_playerprojectile.GetWidth(), 0) << "PlayerProjectile width should not be 0.";
}

TEST(PlayerProjectile, ParemterizedConstructor) {
  PlayerProjectile my_playerprojectile(5, 8);
  ASSERT_EQ(my_playerprojectile.GetX(), 5) << "PlayerProjectile objects' x location should be set to the first parameter.";
  ASSERT_EQ(my_playerprojectile.GetY(), 8) << "PlayerProjectile objects' y location should be set to the second parameter.";
  ASSERT_NE(my_playerprojectile.GetHeight(), 0) << "PlayerProjectile height should not be 0.";
  ASSERT_NE(my_playerprojectile.GetWidth(), 0) << "PlayerProjectile width should not be 0.";
}

void PlayerProjectileDraw() {
  PlayerProjectile my_playerprojectile(10, 10);
  int width = my_playerprojectile.GetWidth();
  int height = my_playerprojectile.GetHeight();
  graphics::Image test_screen(800, 600);
  ASSERT_DURATION_LE(3, {
    my_playerprojectile.Draw(test_screen);
  })
  bool has_drawing = false;
  bool has_extraneous_drawing = false;

  graphics::Color white(255, 255, 255);
  for (int y = 0; y < test_screen.GetHeight(); y++) {
    for (int x = 0; x < test_screen.GetWidth(); x++) {
      if (test_screen.GetColor(x, y) != white) {
        if (x >= 10 && x <= 10 + width && y >= 10 && y <= 10 + height) {
          has_drawing = true;
        } else {
          has_extraneous_drawing = true;
        }
      }
    }
  }
  ASSERT_TRUE(has_drawing) << "The PlayerProjectile object's Draw method should draw an image to the given image object.";
  ASSERT_FALSE(has_extraneous_drawing) << "The PlayerProjectile object's Draw method should only draw inside it's boundaries.";
}

TEST(PlayerProjectile, Draw) {
  ASSERT_EXIT((PlayerProjectileDraw(),exit(0)),::testing::ExitedWithCode(0),".*")
        << "    Should not crash or infinitely loop.";
  PlayerProjectileDraw();
}

TEST(PlayerProjectile, IntersectsWithOpponent) {
  PlayerProjectile my_playerprojectile(40, 100);
  
  Opponent my_left_opponent;
  my_left_opponent.SetX(40 - (my_left_opponent.GetWidth() - 1));
  my_left_opponent.SetY(100);
  ASSERT_TRUE(my_playerprojectile.IntersectsWith(my_left_opponent)) << "A PlayerProjectile object must check if an Opponent intersects with it's left side.";

  Opponent my_right_opponent;
  my_right_opponent.SetX(40 + my_playerprojectile.GetWidth() - 1);
  my_right_opponent.SetY(100);
  ASSERT_TRUE(my_playerprojectile.IntersectsWith(my_right_opponent)) << "A PlayerProjectile object must check if an Opponent intersects with it's right side.";

  Opponent my_top_opponent;
  my_top_opponent.SetX(40);
  my_top_opponent.SetY(100 - (my_top_opponent.GetHeight() - 1));
  ASSERT_TRUE(my_playerprojectile.IntersectsWith(my_top_opponent)) << "A PlayerProjectile object must check if an Opponent intersects with it's top side.";

  Opponent my_bottom_opponent;
  my_bottom_opponent.SetX(40);
  my_bottom_opponent.SetY(100 + my_playerprojectile.GetHeight() - 1);
  ASSERT_TRUE(my_playerprojectile.IntersectsWith(my_bottom_opponent)) << "A PlayerProjectile object must check if an Opponent intersects with it's top side.";
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
