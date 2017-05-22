#include "ScoreComponent.h"
#include "Text.h"

ScoreComponent::ScoreComponent(Text * scoreText) : Component(SCORE_COMPONENT)
{
    _scoreText = scoreText;
}

ScoreComponent::~ScoreComponent()
{
}

void ScoreComponent::changeScore(int difScore)
{
    int score = _score + difScore * _multiplier;    
    if (score <= 0)
    {
        _score = 0;
        return;
    }
    _score += difScore * _multiplier;
}

void ScoreComponent::changeName(std::string name)
{
    _name = name;
}

std::string ScoreComponent::returnName()
{
    return _name;
}

unsigned int ScoreComponent::returnScore()
{
    return _score;
}

void ScoreComponent::LateUpdate(float deltaTime)
{
    
}

void ScoreComponent::Update(float deltaTime)
{
    //TODO: convert this to the distance not time
    _updateTimer -= deltaTime;
    _mulitplierUpdateTimer -= deltaTime;

    if (_updateTimer < 0.0f)
    {
        changeScore(1);
        _updateTimer = 0.2f;
    }

    if( _mulitplierUpdateTimer < 0.0f)
    {
        incMultiplier();
        _mulitplierUpdateTimer = 10.0f * _multiplier;
    }
    _scoreText->Update("Score: " + std::to_string(_score) + " X" + std::to_string(_multiplier));
}


