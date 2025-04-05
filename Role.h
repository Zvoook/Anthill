#pragma once
#include "Game Settings.h"

class Role {
public:
    virtual ~Role() = default;
    virtual void role_up(weak_ptr<Ant> ant) = 0;
    virtual void work(weak_ptr<Ant> ant) = 0;
};

class Baby : public Role {
public:
    Baby() = default;
    void work(weak_ptr<Ant> ant) override {};
    void role_up(weak_ptr<Ant> weak) override;
};

class Sitter : public Role {
public:
    Sitter() = default;
    void work(weak_ptr<Ant> ant) override {};
    void role_up(weak_ptr<Ant> ant) override;
};

class Collector : public Role {
public:
    Collector() = default;
    void work(weak_ptr<Ant> ant) override;
    void role_up(weak_ptr<Ant> ant) override;
};

class Builder : public Role {
public:
    Builder() = default;
    void work(weak_ptr<Ant> ant) override;
    void role_up(weak_ptr<Ant> ant) override;
};

class Soldier : public Role {
public:
    Soldier() = default;
    void work(weak_ptr<Ant> ant) override;
    void role_up(weak_ptr<Ant> ant) override;
};

class Shepperd : public Role {
public:
    Shepperd() = default;
    void work(weak_ptr<Ant> ant) override;
    void role_up(weak_ptr<Ant> ant) override;
};

class Cleaner : public Role {
public:
    Cleaner() = default;
    void work(weak_ptr<Ant> ant) override;
    void role_up(weak_ptr<Ant> ant) override;
};