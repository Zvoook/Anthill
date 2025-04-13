#include "Role.h"
#include "Ant.h"
#include "Resource.h"
#include "Cemetery.h"

void Sitter:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ ��� ����
    // �� ������ ������ ������ ����������
}

void Builder:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ ��� ���������
    // �� ������ ������ ������ ����������
}

void Collector:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ ��� ��������
    // �� ������ ������ ������ ����������
}

Soldier::Soldier() {
    damage = rand() % 21 + 30;
}

void Soldier:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ ��� �������
    // ����� �������� �������� ������� ������
    // if (raid_flag == 1)
}

void Soldier::attack(Ant& ant) {
    // ������ ����� �����
}

void Soldier::escape_from_enemy(Ant& ant) {
    // ������ ����������� �� �����
}

void Soldier::set_on_enemy(Ant& ant) {
    // ������ ��������� �� �����
}

void Shepperd:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ ��� �������
    // ��������, ����� � ������������ ���
}

void Cleaner:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // ������ � ��� ���� ������ ������ � ������� � ��������
    // ����� �������� �������� ������ ������

    //// ���� ������� �� ����� ������ - ���� ����� ������
    //if (!is_carrying_waste(ant)) {
    //    seek_bodies(resources, ant);
    //    seek_trash(resources, ant);
    //}
    //// ���� ������� ����� ������ � �� ����� ����, ���������� �� ��������
    //else if (!ant.has_valid_target()) {
    //   // deliver_to_cemetery(ant);
    //}
}

// ��������� ������ Cleaner �������� ��� ���������
void Cleaner::seek_bodies(std::vector<Resource>& resources, Ant& ant)
{
    // ���� ������� ��� ���� ���-�� ��� ����� ����, �������
    if (ant.has_valid_target() || ant.get_inventory() != no_res)
        return;

    // ������������� ��������� ������� � ������� ������
    for (auto& res : resources) {
        if (!res.is_visible() || res.get_type() != body)
            continue;

        // ���������, ��������� �� ���� � ���� ������ �������
        Position antPos = ant.get_pos();
        Position resPos = res.get_posit();
        float dx = antPos.x - resPos.x;
        float dy = antPos.y - resPos.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= ant.get_vision_circle().getRadius()) {
            // ������� ����� ���� - ��������� ���� � ���������
            ant.set_target(resPos);
            ant.set_inventory(body);
            res.set_invisible(); // �������� ������ ��� �����������
            break;
        }
    }
}

// ��������� ������ ��� ���������...