//#pragma once
//#include "Game Settings.h"
//#include <map>
//#include "Ant.h"
//#include "Resource.h"
//
//class Informers {
//private:
//    // ������ ��������: ������ ������������� ���� ������� (��. enum res_type)
//    // resources[0] � ��� no_res 
//    // resources[1] � ��� food,
//    // resources[2] � ��� stick,
//    // resources[3] � ��� aphid,
//    // resources[4] � ��� body,
//    // resources[5] � ��� trash.
//    vector<vector<Resource*>> resources;
//
//    // ������� ������������ �� �����: ���� � ����� ���� (��������, ������������ Ant::get_role())
//    map<int, vector<Ant*>> ants_by_role;
//    float detect_dist;
//
//public:
//    // �����������: �������������� ������ ����������� � �������������� ������ ��� 6 ����� ��������.
//    Informers(float detect_dist) : detect_dist(detect_dist) { resources.resize(6); }
//
//    // �����������/�������� �������
//    void subscribe_ant(Ant* ant);
//    void unsubscribe_ant(Ant* ant);
//
//    // �����������/�������� ������� � ������ ����������� � ���-������ �������� ��� ���� (�������� �� enum)
//    void subscribe_resource(Resource* resource);
//    void unsubscribe_resource(Resource* resource);
//
//    // �������� ����������: ����� �������� � ���������� ����� ��������, ���� ������ �����,
//    // ������� (is_visible()) � ���������� > 0.
//    void update_status();
//
//    // ��������, ��������� �� ������ � ���� ����������� �������
//    bool can_see(Ant* ant, Resource* resource);
//
//    // ���������� ������� ���������� ���������� ������� ���������� ����
//    void add_resource(Resource* resource);
//
//    // �������������� ���������� �������� � �������, ���� ������� ������� �� ����� ��� ���������
//    void inform_about_resource(Ant* informer_ant, Resource* resource);
//
//    // ����� ���������� ���������� ������� � ��������� ����� ��� ������� �������
//    Ant* find_free_ant(Resource* resource, int role_id);
//
//    // ������� ���������� � ������� (��������, ����� ��� ���������� ���������� 0)
//    void clear_info(Resource* resource);
//};