#include "MoveStrategy.h"
class DriveMovement : public MoveStrategy
{
public:
	DriveMovement() = default;
	~DriveMovement() {};
	DriveMovement(DriveMovement&& other);
	virtual void execute(sf::Sprite*) override;
private:
};