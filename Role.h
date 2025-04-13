#pragma once
#include "Game Settings.h"
class Ant;

class Role {
public:
    virtual void work(Ant* self) = 0;
    virtual ~Role() = default;
};

class Baby : public Role {
public:
    Baby() = default;
    void work(Ant* self) override;
};

class Sitter : public Role {
public:
    Sitter() = default;
    void work(Ant* self) override;
};

class Collector : public Role {
public:
    Collector() = default;
    void work(Ant* self) override;
};

class Builder : public Role {
public:
    Builder() = default;
    void work(Ant* self) override;
};

class Soldier : public Role {
public:
    Soldier();
    void work(Ant* self) override;
    void attack();
    void escape_from_enemy();
    void set_on_enemy();
private:
    int damage;
};

class Shepperd : public Role {
public:
    Shepperd() = default;
    void work(Ant* self) override;
};

class Cleaner : public Role {
public:
    Cleaner() = default;
    void work(Ant* self) override;
};