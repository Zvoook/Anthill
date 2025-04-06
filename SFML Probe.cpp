#include <SFML/Graphics.hpp>
using namespace sf;
#ifdef Cir
int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 1000), L"Testings");
    /*sf::CircleShape circle(300.f,8);
    circle.setPosition(sf::Vector2f(300, 300));
    circle.move(-20, -250);
    circle.setFillColor(sf::Color(150,20,215));
    circle.setOutlineThickness(30.f);
    circle.setOutlineColor(sf::Color::Yellow);*/
    sf::ConvexShape conv;
    sf::ContextSettings sets;
    sets.antialiasingLevel = 12;
    conv.setPointCount(5);
    conv.setPoint(0, sf::Vector2f(100.f, 20.f));
    conv.setPoint(1, sf::Vector2f(50.f, 70.f));
    conv.setPoint(2, sf::Vector2f(880.f, 10.f));
    conv.setPoint(3, sf::Vector2f(750.f, 100.f));
    conv.setPoint(4, sf::Vector2f(500.f, 300.f));
    conv.setFillColor(sf::Color::Red);
    //Font font;
    //font.loadFromFile("C:\\Users\\Dmitriy\\Учебка\\Programming\\Gilroy - ExtraBold.otf");
    //Text text("Hi Hitler!", font);
    //text.setCharacterSize(150);
    //text.setStyle(Text::Bold);
    ////text.setColor(Color::Black);
    //text.setPosition(100, 100);
    //sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type==sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::Red);
        window.draw(text);
        window.display();
    }
}
#endif
#ifdef Wav
int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 400), L"Иллюзия", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    sf::Vector2f a1{ 100,100 };
    sf::Vector2f a2{ 500,200 };
    sf::Vector2f a3{ 500,200 };
    sf::Vector2f a4{ 100,300 };
    bool lu = true;
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setFillColor(sf::Color::Magenta);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (lu) { a1.y += 1; a4.y -= 1; a2.y -= 1; a3.y += 1; if (a1.y > 200) lu = false; }
        else { a1.y -= 1; a4.y += 1; a2.y += 1; a3.y -= 1; if (a1.y < 100) lu = true; }
        convex.setPoint(0, a1);
        convex.setPoint(1, a2);
        convex.setPoint(2, a3);
        convex.setPoint(3, a4);
        window.clear(sf::Color::Blue);
        window.draw(convex);
        window.display();
    }
    return 0;
}
#endif