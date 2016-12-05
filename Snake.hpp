#ifndef SNAKE
#define SNAKE
#include <SFML/Graphics.hpp>
#define RADIUS 10

class Snake : public sf::Drawable {
private:
	sf::CircleShape m_head;
	SnakePart* m_body;
	SnakePart* m_tail;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(m_head, states);
	}

	class SnakePart : public sf::Drawable {
	private:
		sf::CircleShape m_part;
		SnakePart* m_next;
	public:
		SnakePart(float x, float y) : m_next(nullptr) {
			m_part.setRadius(RADIUS);
			m_part.setFillColor(sf::Color(0, 123, 123));
			m_part.setPosition(x, y);
		};

		void next(SnakePart* _next) {
			m_next = _next;
		}

		SnakePart* next() {
			return m_next;
		}

		void move(float o_x, p_y) {
			m_part.move(o_x, p_y);
		}

		void move(const sf::Vector2f& offset) {
			m_part.move(offset);
		}

	};

public:
	Snake(float start_x, float start_y) : {
		m_head.setRadius(RADIUS);	
		m_head.setFillColor(sf::Color(0, 210, 210));
		m_head.setPosition(start_x, start_y);
	}

	void addToBody(float x, float y) {
		SnakePart* toAdd = new SnakePart(x, y);
		
	}

	void removeTail {

	}



};
#endif // SNAKE
