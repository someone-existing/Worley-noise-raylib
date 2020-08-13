#include "raylib.h"
#include <cmath>
using namespace std;
int screenWidth = 800;
int screenHeight = 450;
int maxPoints = 100;
struct Points
{
    int x, y;
};
int GetPixelColor(int x, int y, Points points[]){
    //Generate array of distances
    int d[maxPoints];
    for (int i = 0; i < maxPoints; i++){
        d[i] = sqrt((x - points[i].x)*(x - points[i].x) + (y - points[i].y)*(y - points[i].y));
    }
    //Get smallest distance from array
    int mindist = screenHeight*screenWidth;
    for (int i = 0; i < maxPoints; i++){
        if(d[i] < mindist){
            mindist = d[i];
        }
    }
    return 120+mindist;
}
void DrawGame(Points points[]){
    int d = (screenWidth + screenHeight)*(screenWidth + screenHeight);
    for (int x = 0; x < screenWidth; x++)
    {
        for (int y = 0; y < screenHeight; y++)
        {
            DrawPixel(x, y, {0, 0, 0, GetPixelColor(x, y, points)});
        }
    }
//    for (int i = 0; i < maxPoints; i++){
//        DrawRectangle(points[i].x, points[i].y, 10, 10, {0, 255, 0, 255});
//    }
}
void InitPoints(Points point[]){
    for (int i = 0; i < maxPoints; i++)
    {
        point[i].x =  GetRandomValue(0, screenWidth);
        point[i].y = GetRandomValue(0, screenHeight);
    }
}
int main(int argc, char* argv[])
{
    Points points[maxPoints];
    InitWindow(screenWidth, screenHeight, "Worley Noise");
    SetTargetFPS(60);
    InitPoints(points);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        if(IsMouseButtonPressed(0)){
            InitPoints(points);
        }
        DrawGame(points);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}