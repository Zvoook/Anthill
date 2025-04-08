#pragma once
#include "Game Settings.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void work() = 0;
    //virtual Role* role_up(Ant& ant) = 0;
};

class Baby : public Role {
public:
    Baby() = default;
    void work() override {}
    //Role* role_up(Ant& ant) override { return roles[1]; }
};

class Sitter : public Role {
public:
    Sitter() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};

class Collector : public Role {
public:
    Collector() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};

class Builder : public Role {
public:
    Builder() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};

class Soldier : public Role {
public:
    Soldier() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};

class Shepperd : public Role {
public:
    Shepperd() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};

class Cleaner : public Role {
public:
    Cleaner() = default;
    void work() override;
    //Role* role_up(Ant& ant) override;
};