void Sitter::role_up(shared_ptr<Ant> ant){
    int chance = rand() % 100;
    if (chance < 50) ant->set_role(make_shared<Builder>());
    else  ant->set_role(make_shared<Collector>());
}
void Sitter::work(shared_ptr<Ant> ant)
{
}
