// create class for buttons with starting point x,y, width, height, and content text, and id

#include "LCD_GUI.h"

class Button {
  public:
    POINT x1, y1, x2, y2;
    int class_id, id;
    char* text;
    Button(int x1, int y1, int x2, int y2, char* text, int class_id, int id) {
      this->x1 = x1;
      this->y1 = y1;
      this->x2 = x2;
      this->y2 = y2;
      this->text = text;
      this->id = id;
      this->class_id = class_id;
    }
    void draw() {
      GUI_DrawRectangle(x1, y1, x2, y2, BLUE, DRAW_EMPTY, DOT_PIXEL_1X1);
      GUI_DisString_EN(x1 + 10, y1 + 10, text, &Font16, WHITE, BLACK);
    }
    void clear() {
        GUI_DrawRectangle(x1 + 1, y1 + 1, x2 - 1, y2 - 1, WHITE, DRAW_FULL, DOT_PIXEL_1X1);
    }
    void displayNumber(int number) {
        GUI_DisNum(x1 + 10, y1 + 10, number, &Font16, WHITE, BLACK);
    }
    bool contains(int px, int py) {
      return (px > x1 && px < x2 && py > y1 && py < y2);
    }
};