#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_ROWS 3

struct Board {
    int number_rows;              
    int number_matches[MAX_ROWS];  
};

void drawBoard(sf::RenderWindow& window, Board *board, sf::Texture& matchTexture, sf::Sprite& backgroundSprite, sf::Text& titleText) {
    window.clear(sf::Color::White);
    
    window.draw(backgroundSprite); 
    window.draw(titleText);

    sf::Sprite matchSprite;
    matchSprite.setTexture(matchTexture);
    matchSprite.setScale(0.3f, 0.3f);
  
    for (int y = 0; y < MAX_ROWS; y++) {
        for (int x = 0; x < board->number_matches[y]; x++) {
            matchSprite.setPosition(x * 130 + 150, y * 130 + 200);
            window.draw(matchSprite);
        }  
    }
}

void playersTurn(sf::RenderWindow& window, Board *board) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);

    for (int y = 0; y < MAX_ROWS; y++) {
        int rowStartX = 150;
        int rowStartY = y * 130 + 200;
        int rowEndX = rowStartX + board->number_matches[y] * 130;
        
        if (localPosition.x >= rowStartX && localPosition.x < rowEndX &&
            localPosition.y >= rowStartY && localPosition.y < rowStartY + 130) {
            int matchIndex = (localPosition.x - rowStartX) / 130;
            if (matchIndex < board->number_matches[y]) {
                board->number_matches[y] = matchIndex;
            } else {
                board->number_matches[y] = 0;
            }
            return;
        }
    }
}

void computerTurn(Board *board) {
    int nim_sum = 0;
    for (int i = 0; i < board->number_rows; i++) {
        nim_sum ^= board->number_matches[i];
    }
    
    if (nim_sum == 0) {
        int row;
        do {
            row = rand() % MAX_ROWS;
        } while (board->number_matches[row] == 0);

        int matchesToRemove = rand() % (board->number_matches[row]) + 1;
        board->number_matches[row] -= matchesToRemove;
    } else {
        for (int i = 0; i < board->number_rows; i++) {
            int nim_sum_temp = nim_sum ^ board->number_matches[i];
            if (nim_sum_temp < board->number_matches[i]) {
                board->number_matches[i] = nim_sum_temp;
                break;
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "NIM");
    std::srand(std::time(nullptr));

    Board board;
    board.number_rows = MAX_ROWS;
    board.number_matches[0] = 3;
    board.number_matches[1] = 4;
    board.number_matches[2] = 6;
    int turn = 0; // 0 - игрок, 1 - компьютер

    sf::Texture matchTexture;
    if (!matchTexture.loadFromFile("match.png")) {
        std::cerr << "Failed to load match image!" << std::endl;
        return -1;
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background2.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
        static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y
    );

    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Game Nim");
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(400, 50);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (turn == 0 && event.type == sf::Event::MouseButtonPressed) {
                playersTurn(window, &board);
                turn = 1;
            }
        }
        
        drawBoard(window, &board, matchTexture, backgroundSprite, titleText);
        window.display();
        if (turn == 1) {
            sf::sleep(sf::milliseconds(1000));
            computerTurn(&board);
            turn = 0;
        }
    }

    return 0;
}

