#pragma once
#include <vector>



class Anthill {
public:
    Anthill();
    ~Anthill();
    void up_lvl();
    void bring_material(int rank_material); //��� ��� � ���������� ���� ������� ��������� ������� ����� ���������
    void bring_food(int rank_food); //��� ��������� ������� ���
private:
    int lvl;
    int current_food;
    int current_materials;
    int current_ants;
    int place_for_food;
    int place_for_materials;
    int place_for_ants;
    // std::vector<> soldiers;
    // std::vector<> builders;
    // std::vector<> cleaners;
    // std::vector<> babysitters;
    // std::vector<> babies;
    // std::vector<> shepherds;
};



