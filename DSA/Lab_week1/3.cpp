Character::Character() {
    x = y = hp = 0;
}

Character::Character(int hp, int x, int y) {
    this->hp = hp;  this->x = x;    this->y = y;
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getX() {
    return x;
}

void Character::setX(int x) {
    this->x = x;
}

int Character::getY() {
    return y;
}

void Character::setY(int y) {
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    return abs(x-other->x) + abs(y-other->y);
}