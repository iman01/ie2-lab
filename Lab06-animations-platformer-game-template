#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite(const int fps, const std::string& path) //make an initializer list for fps_
    {

        //load the texture here
        //set Texture
        setTextureRect(sf::IntRect(50, 0, 50, 37));
    }

    void setSpeed(const int& x_speed, const int& y_speed, const int & ro_speed) {
        x_speed_ = x_speed;
        y_speed_ = y_speed;
        ro_speed_ = ro_speed;
    }

    void animate(const sf::Time &elapsed){
        bouncce();
        float dt = elapsed.asSeconds();


        // based on dt and fps_ fins fragments_index here

        setTextureRect(running_frames[fragments_index]);

        move(x_speed_*dt,y_speed_*dt);
    }

    void setBounds(const float& l_bound, const float& r_bound,const float& u_bound,const float& d_bound){
        l_bound_  = l_bound  ;
        r_bound_  = r_bound  ;
        u_bound_  = u_bound  ;
        d_bound_  = d_bound  ;
    }

    void add_animation_frame(const sf::IntRect& frame){
        //add animation frames to vector


    }
private:
    sf::Texture texture_;
    int fps_;
    int x_speed_ = 0 ;
    int y_speed_ = 0 ;
    int ro_speed_ = 0 ;
    float l_bound_ = 0;
    float r_bound_ = 0;
    float u_bound_ = 0;
    float d_bound_ = 0;
    float t_ = 0.0;
    unsigned int fragments_index = 0;
    std::vector<sf::IntRect> running_frames;



    void bouncce(){
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(rectangle_bounds.top <= u_bound_){
            y_speed_ = abs(y_speed_);
        }

        if(rectangle_bounds.top + rectangle_bounds.height >= d_bound_){
            y_speed_ = abs(y_speed_) * -1;
        }

        if(rectangle_bounds.left <= l_bound_ ){
           x_speed_ = abs(x_speed_);
        }

        if(rectangle_bounds.left + rectangle_bounds.width >= r_bound_){
            x_speed_ = abs(x_speed_) * -1;
        }
    }


};





int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


    AnimatedSprite hero(10, "Character\\character.png");
    hero.setBounds(0, window.getSize().x, 0, window.getSize().y);
    hero.setSpeed(30,30,10);


    //hero.add_animation_frame(sf::IntRect(0, 0, 50, 37)); // hero standing frame 1
    //hero.add_animation_frame(sf::IntRect(50, 0, 50, 37)); // hero standing frame 2
    //hero.add_animation_frame(sf::IntRect(100, 0, 50, 37)); // hero standing frame 3
    hero.add_animation_frame(sf::IntRect(150, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(200, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(250, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(300, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(350, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(400, 0, 50, 37)); // hero running frame 1



    sf::Clock clock;



    // run the program as long as the window is open
    while (window.isOpen()) {
    hero.setTextureRect(sf::IntRect(50, 0, 50, 37));
    hero.setScale(1.5,1.5);

        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
           hero.animate(elapsed);
        }




        window.clear(sf::Color::Black);

        sf::Texture texture;
        if (!texture.loadFromFile("grass.png")) {
            std::cerr << "Could not load texture" << std::endl;
            return 1;
        }
        texture.setRepeated(true);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));

        // draw everything here...
        window.draw(sprite);
        window.draw(hero);



        // end the current frame
        window.display();
    }

    return 0;
}
