#include "Role.h"
#include "Ant.h"
#include "Resource.h"
#include "Cemetery.h"

void Sitter:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Логика для няни
    // На данный момент пустая реализация
}

void Builder:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Логика для строителя
    // На данный момент пустая реализация
}

void Collector:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Логика для сборщика
    // На данный момент пустая реализация
}

Soldier::Soldier() {
    damage = rand() % 21 + 30;
}

void Soldier:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Логика для солдата
    // Можно добавить проверку наличия врагов
    // if (raid_flag == 1)
}

void Soldier::attack(Ant& ant) {
    // Логика атаки врага
}

void Soldier::escape_from_enemy(Ant& ant) {
    // Логика отступления от врага
}

void Soldier::set_on_enemy(Ant& ant) {
    // Логика наведения на врага
}

void Shepperd:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Логика для пастуха
    // Например, поиск и обслуживание тли
}

void Cleaner:: work(Ant& ant, std::vector<Resource>& resources,vector<Enemy>& enemies)
{
    // Теперь у нас есть прямой доступ к муравью и ресурсам
    // Можем напрямую вызывать другие методы

    //// Если муравей не несет отходы - ищем новые задачи
    //if (!is_carrying_waste(ant)) {
    //    seek_bodies(resources, ant);
    //    seek_trash(resources, ant);
    //}
    //// Если муравей несет отходы и не имеет цели, направляем на кладбище
    //else if (!ant.has_valid_target()) {
    //   // deliver_to_cemetery(ant);
    //}
}

// Остальные методы Cleaner остаются без изменений
void Cleaner::seek_bodies(std::vector<Resource>& resources, Ant& ant)
{
    // Если муравей уже несёт что-то или имеет цель, выходим
    if (ant.has_valid_target() || ant.get_inventory() != no_res)
        return;

    // Просматриваем доступные ресурсы в поисках трупов
    for (auto& res : resources) {
        if (!res.is_visible() || res.get_type() != body)
            continue;

        // Проверяем, находится ли труп в поле зрения муравья
        Position antPos = ant.get_pos();
        Position resPos = res.get_posit();
        float dx = antPos.x - resPos.x;
        float dy = antPos.y - resPos.y;
        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= ant.get_vision_circle().getRadius()) {
            // Муравей нашёл труп - установим цель и инвентарь
            ant.set_target(resPos);
            ant.set_inventory(body);
            res.set_invisible(); // Помечаем ресурс как подобранный
            break;
        }
    }
}

// Остальные методы без изменений...