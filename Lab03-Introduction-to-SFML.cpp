#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(50.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(2);
    triangle.setPosition(600.0, 100.0);
    sf::Clock clock;

    int rectangle_velocity_x = 5;
    int rectangle_velocity_y = 15;
    int rectangle_angular_velocity = 10;

    bool flag_y = false;
    bool flag_x = false;


    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        rectangle.move(rectangle_velocity_x*dt,rectangle_velocity_y*dt);
        rectangle.rotate(rectangle_angular_velocity*dt);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
        std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

        if(rectangle_bounds.top<=0 || rectangle_bounds.top+rectangle_bounds.height>=window.getSize().y)
            {
                if(flag_y != true)
                {
                    rectangle_velocity_y *= -1;
                    rectangle.setFillColor(sf::Color(rand() % 256,
                                                     rand() % 256,
                                                     rand() % 256));
                }
                flag_y = true;
            }
            else
                flag_y = false;



            if(rectangle_bounds.left<=0 || rectangle_bounds.left+rectangle_bounds.width>=window.getSize().x)
            {
                if(flag_x!=true)
                {
                    rectangle_velocity_x *= -1;
                    rectangle.setFillColor(sf::Color(rand() % 256,
                                                     rand() % 256,
                                                     rand() % 256));
                }
                flag_x = true;
            }
            else
                flag_x = false;





        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
