#include <raylib.h>

class Bullet {
private:
	Rectangle rect;
	Vector2 position;
	const char* direction;
	Color color;
	bool active;
	int speed;
public:
	Bullet(Vector2 posision, int speed, const char* direction, Color color);
	Bullet();
	void Draw();
	void Update();
	Rectangle GetRect();
};