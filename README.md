# SILI Game: Milestone 01
In this first milestone, you will create four images that represent the game elements in your SILI game. You will use the `graphics::Image` class to create objects that draw your game elements and save them to a bitmap file (.bmp).

All your code will be written in `main.cc`.

## User input
You program starts by asking the user to provide the file names for your three game elements. We assume that users will provide valid filenames so you do not need to implement any error handling. We also assume that the user will use a .bmp extension for the filename. Kindly follow the program output exactly shown below. Take note that the bold text refers to user input.

<pre>
Please provide player image filename: <b>player.bmp</b>
Please provide opponent image filename: <b>opponent.bmp</b>
Please provide player projectile image filename: <b>p_projectile.bmp</b>
Please provide opponent projectile image filename: <b>o_projectile.bmp</b>
</pre>

## Player
Create a `graphics::Image` object that you will use to draw the player's character. It is highly encouraged that you use a 50 x 50 pixel image so that it will fit well on the game screen when we start building the game.

## Opponent
Create a `graphics::Image` object that you will use to draw the opponent's character. It is highly encouraged that you use a 50 x 50 pixel image so that it will fit well on the game screen when we start building the game. Take note that when you build the game, there will be multiple opponents drawn on the screen.

## Player Projectile
Create a `graphics::Image` object that you will use to draw the player's projectile. It is highly encouraged that you use a 5 x 5 pixel image so that it will fit well on the game screen when we start building the game. The projectile is launched by the player that will defeat the opponent when they collide.

## Opponent Projectile
Create a `graphics::Image` object that you will use to draw the opponent's projectile. It is highly encouraged that you use a 5 x 5 pixel image so that it will fit well on the game screen when we start building the game. The projectile is launched by the opponent that will defeat the player when they collide.

## The `graphics::Image` class
The `graphics::Image` class allows you to represent and perform operations on images. You can create a `graphics::Image` object much like how you would create other variables. However, it requires you to provide it's width and height. The example below shows an example of creating it.

```cpp
graphics::Image my_image(800, 600);
```

`graphics::Image` provides several member functions you can use to draw on the screen. The table below lists all the member function prototypes you can use for drawing.

| Member function prototype 	| Description 	|
|-	|-	|
| bool SetRed (int x, int y, int r); 	| Set the red intensity of pixel at (x, y) to r 	|
| bool SetGreen(int x, int y, int g); 	| Set the green intensity of pixel at (x, y) to g 	|
| bool SetBlue(int x, int y, int b); 	| Set the blue intensity of pixel at (x, y) to b 	|
| bool DrawLine(int x0, int y0, int x1, int y1, int red, int green, int blue, int thickness = 1); 	| Draw a line from (x0, y0) to (x1, y1) with the corresponding red, green, and blue intensities using the provided thickness. 	|
| bool DrawCircle(int x, int y, int radius, int red, int green, int blue); 	| Draw a circle with center at (x, y) with the corresponding red, green, and blue intensities and specified radius. 	|
| bool DrawRectangle(int x, int y, int width, int height, int red, int green, int blue); 	| Draw a rectangle whose top-left vertex is at (x, y), with the specified width and height, and filled with the corresponding red, green, and blue instensities. 	|
| bool DrawPolygon(const std::vector<int>& points, int red, int green, int blue); 	| Draw a polygon whose vertices are listed in the given vector with the specified red, green, and blue intensities. Each vertex is represented by its x and y coordinate, and are listed sequentially in the vector. For example, a polygon with three vertices (0, 0), (0, 2), (2,1) is represented as a vector of integers {0, 0, 0, 2, 2, 1}. The last vertex will connect with the first vertex in* the list. 	|
| bool DrawText(int x, int y, const std::string& text, int font_size, int red, int green, int blue); 	| Draws text starting at (x, y) with the given string having the specified font size and the specified red, green, and blue intensities. 	|
| bool SaveImageBmp(const std::string& filename) const; | Saves the image as a bmp file with the given filename. |

## Compiling and running the program
To manually test your code you can compile and run this program with:

```
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

*Note: you need a few additional flags on Mac which are not shown here.*

However, that's a lot to type, so we've included a shortcut to compile and create ``main``:

```
make build
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

## Run the style and format checkers

You can use two checkers to avoid common errors and make sure your code is easy to read. Use their output to follow programming best practices and make your code readable.

```
make stylecheck
```

```
make formatcheck
```

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).
1. Answered the questions in `reflection.md`

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc cpputils/graphics/image.cc -o main -lm -lX11 -lpthread
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission

We recommend pushing to Github frequently to back up your work.
