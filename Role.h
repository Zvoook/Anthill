#pragma once
#include "Game Settings.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void work() = 0;
};

class Baby : public Role {
public:
    Baby() = default;
    void work() override {}
};

class Sitter : public Role {
public:
    Sitter() = default;
    void work() override;
};

class Collector : public Role {
public:
    Collector() = default;
    void work() override;
};

class Builder : public Role {
public:
    Builder() = default;
    void work() override;
};

class Soldier : public Role {
public:
    Soldier();
    void work() override;
    void attack();
    void escape_from_enemy();
    void set_on_enemy();
private:
    int damage;
};

class Shepperd : public Role {
public:
    Shepperd() = default;
    void work() override;
};

class Cleaner : public Role {
public:
    Cleaner() = default;
    void work() override;
};