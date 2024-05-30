#include <iostream>
#include <raylib.h>
using namespace std;

Color Green = Color{ 40,190,160,255 };
Color Dark_Green = Color{ 20,160,130,255 };
Color Light_Green = Color{ 130,210,190,255 };
Color Yellow = Color{ 250,220,100,255 };

int player1_score = 0;
int player2_score = 0;

int player_score = 0;
int cpu_score = 0;

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    void Draw() {
        DrawCircle(x, y, radius, YELLOW);
    }

    void update() {
        x += speed_x;
        y += speed_y;
        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth()) {
            if (cpu_score >= 10) { // Check if CPU wins
                cout << "CPU wins!" << endl;
            }
            cpu_score++;
            ResetBall();
        }
        if (x - radius <= 0) {
            if (player_score >= 10) { // Check if Player wins
                cout << "Player wins!" << endl;
            }
            player_score++;
            ResetBall();
        }
        if (x + radius >= GetScreenWidth()) {
            player1_score++; // Increment player1_score
            if (player1_score >= 10) { // Check if Player 1 wins
                cout << "Player 1 wins!" << endl;
            }
            ResetBall();
        }
        if (x - radius <= 0) {
            player2_score++; // Increment player2_score
            if (player2_score >= 10) { // Check if Player 2 wins
                cout << "Player 2 wins!" << endl;
            }
            ResetBall();
        }

    }

    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = { -1,1 };
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};


class Paddle {
protected:
    void limitMovement() {
        if (y <= 0) {
            y = 0;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }
public:
    float x, y;
    float width, height;
    int speed;
    void Draw() {
        DrawRectangleRounded(Rectangle{ x,y,width,height }, 0.8, 0, WHITE);
    }
    virtual void update() = 0; // Make update function pure virtual
};

class PlayerPaddle :public Paddle {
public:
    void update() {
        if (IsKeyDown(KEY_UP)) { // Player moves up
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) { // Player moves down
            y += speed;
        }
        limitMovement();
    }
};

class CpuPaddle : public Paddle {
public:
    void update() override {} // This function is not needed for CPU paddle
    void update(int ball_y) {
        if (y + height / 2 > ball_y) {
            y = y - speed;
        }
        if (y + height / 2 <= ball_y) {
            y = y + speed;
        }
        limitMovement();
    }
};

class SecondPlayerPaddle :public Paddle {
public:
    void update() {
        if (IsKeyDown(KEY_W)) { // Player 2 moves up
            y -= speed;
        }
        if (IsKeyDown(KEY_S)) { // Player 2 moves down
            y += speed;
        }
        limitMovement();
    }
};


Ball ball;
PlayerPaddle player1;
SecondPlayerPaddle player2;
CpuPaddle cpu;

int main()
{
    int a;
    cout << "|------------------ Players ------------------|" << endl;
    cout << "|                                            |" << endl;
    cout << "|            1. Single player                |" << endl;
    cout << "|            2. Two players                  |" << endl;
    cout << "|            Enter your option               |" << endl;
    cin >> a;

    if (a == 1)
    {
        cout << "Starting the game " << endl;
        const int screen_width = 1280;
        const int screen_height = 680;
        InitWindow(screen_width, screen_height, "MY PING PONG GAME! ");
        SetTargetFPS(60);

        ball.radius = 20;
        ball.x = screen_width / 2;
        ball.y = screen_height / 2;
        ball.speed_x = 7;
        ball.speed_y = 7;

        player1.width = 25;
        player1.height = 120;
        player1.x = screen_width - player1.width - 10;
        player1.y = screen_height / 2 - player1.height / 2;
        player1.speed = 6;

        cpu.width = 25;
        cpu.height = 120;
        cpu.x = 10;
        cpu.y = screen_height / 2 - cpu.height / 2;
        cpu.speed = 6;

        while (WindowShouldClose() == false) {
            BeginDrawing();

            ball.update();
            player1.update(); // Update player1
            cpu.update(ball.y);

            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player1.x,player1.y,player1.width,player1.height })) {
                ball.speed_x *= -1;
            }
            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ cpu.x,cpu.y,cpu.width,cpu.height })) {
                ball.speed_x *= -1;
            }

            ClearBackground(Dark_Green);
            DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
            DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
            ball.Draw();
            cpu.Draw();
            player1.Draw(); // Draw player1
            DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);

            EndDrawing();
        }

        CloseWindow();
    }

    if (a == 2)
    {
        cout << "Starting the game with two players" << endl;
        const int screen_width = 1280;
        const int screen_height = 680;
        InitWindow(screen_width, screen_height, "MY PING PONG GAME! ");
        SetTargetFPS(60);

        ball.radius = 20;
        ball.x = screen_width / 2;
        ball.y = screen_height / 2;
        ball.speed_x = 7;
        ball.speed_y = 7;

        player1.width = 25;
        player1.height = 120;
        player1.x = screen_width - player1.width - 10;
        player1.y = screen_height / 2 - player1.height / 2;
        player1.speed = 6;

        player2.width = 25;
        player2.height = 120;
        player2.x = 10;
        player2.y = screen_height / 2 - player2.height / 2;
        player2.speed = 6;

        while (WindowShouldClose() == false) {
            BeginDrawing();

            ball.update();
            player1.update();
            player2.update();

            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player1.x,player1.y,player1.width,player1.height })) {
                ball.speed_x *= -1;
            }
            if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player2.x,player2.y,player2.width,player2.height })) {
                ball.speed_x *= -1;
            }

            ClearBackground(Dark_Green);
            DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
            DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
            ball.Draw();
            player1.Draw();
            player2.Draw();
            DrawText(TextFormat("%i", player1_score), screen_width / 4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i", player2_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);


            EndDrawing();
        }


        CloseWindow();
    }

    return 0;
}
