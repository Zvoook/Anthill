//
//#include "Informers.h"
//
//void Informer::add_ant(Ant* ant) {
//    ants.push_back(ant);  
//}
//void Informer::notify(info_type type, Position pos) {
//    for (auto& ant : ants) {
//        int role_id = ant->get_role();  
//
//        if (type == food_info && role_id == 2) {  // ���� ���� Collector 
//            ant->set_target(pos);  // Collector ���� �������� ���
//        }
//        else if (type == stick_info && role_id == 3) {  // ���� ���� Builder 
//            ant->set_target(pos);  // Builder ���� �������� �����
//        }
//        else if (type == aphid_info && role_id == 5) {  // ���� ���� Shepperd 
//            ant->set_target(pos);  // Shepperd ���� ����� ���
//        }
//        else if (type == enemy && role_id == 4) {  // ���� ���� Soldier 
//            ant->set_target(pos);  // Soldier ���� ��������� � ������
//        }
//        
//    }
//}
//
