#include "Color.hpp"

Color::Color(int c) {
  color = c;
}

Color::newColor(Color *first, Color *prev, int c) {
  prev->next = new Color(c);
  prev->next->next = first;
}
