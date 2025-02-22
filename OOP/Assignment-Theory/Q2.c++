#include <iostream>
using namespace std;

class Ball
{
    int x, y;

public:
    Ball(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

class Robot
{
    string name;
    int hits;

public:
    Robot(string n)
    {
        name = n;
        hits = 0;
    }
    string getName()
    {
        return name;
    }
    int getHits()
    {
        return hits;
    }
    void setName(string n)
    {
        name = n;
    }
    void setHits(int hits)
    {
        this->hits = hits;
    }
    void hitBall(int &ballX, int &ballY, const string direction)
    {
        if (direction == "up")
        {
            ballY++;
            hits++;
        }
        else if (direction == "down")
        {
            ballY--;

            hits++;
        }
        else if (direction == "left")
        {
            ballX--;

            hits++;
        }
        else if (direction == "right")
        {
            ballX++;

            hits++;
        }
        else
        {
            cout << "invalid direction " << endl
                 << endl;
        }
    }
};

class GoalPosition
{
    int x, y;

public:
    GoalPosition(int X, int Y)
    {
        this->x = X;
        this->y = Y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    bool isGoalReached(int BallX, int BallY)
    {
        return (BallX == getX() && BallY == getY());
    }
};

class Team
{
    Robot *robot;
    string teamName;
    bool isGoalMade;

public:
    Team(Robot *robot, string teamName)
    {
        this->robot = robot;
        this->teamName = teamName;
        this->isGoalMade = false;
    }
    Team()
    {
        this->robot = new Robot("R1");
        this->teamName = "Team A";
        this->isGoalMade = false;
    }
    Robot *getRobot()
    {
        return robot;
    }
    void setRobot(Robot *robot)
    {
        this->robot = robot;
    }
    void setIsGoalMade(bool isGoalMade)
    {
        this->isGoalMade = isGoalMade;
    }
    bool getIsGoalMade()
    {
        return isGoalMade;
    }
    void setTeamName(string teamName)
    {
        this->teamName = teamName;
    }
    string getTeamName()
    {
        return teamName;
    }
};

class Game
{
    Team team1;
    Team team2;
    bool isOnesTurn = true;
    Ball ball = Ball(0, 0);
    GoalPosition goalPosition = GoalPosition(3, 3);
    bool isGameStarted = false;

public:
    Game(Team team1, Team team2)
    {
        this->team1 = team1;
        this->team2 = team2;
    }
    void startGame()
    {
        isGameStarted = true;
        cout << "Game started!" << endl;
    }

    void play()
    {
        int x = ball.getX();
        int y = ball.getY();
        string direction;

        cout << "\nNow, Team A Playings: \n"
             << endl;
        while (!team1.getIsGoalMade())
        {
            cout << "Initial Position: " << x << "," << y << endl;
            cout << "Enter hit direction: " << endl;
            cin >> direction;
            team1.getRobot()->hitBall(x, y, direction);

            if (x > 0 && x <= goalPosition.getX())
            {
                ball.setX(x);
            }
            else
            {
                x = ball.getX();
            }
            if (y > 0 && y <= goalPosition.getY())
            {
                ball.setY(y);
            }
            else
            {
                y = ball.getY();
            }
            cout << "\nAfter " << team1.getTeamName() << " Hit: " << x << "," << y << endl;
            if (goalPosition.isGoalReached(ball.getX(), ball.getY()))
            {
                ball.setX(0);
                ball.setY(0);
                x = 0;
                y = 0;
                team1.setIsGoalMade(true);
                cout << "Goal Reached!" << endl;
                cout << "Number of Hits: " << team1.getRobot()->getHits() << endl;
                break;
            }
        }
        cout << "\n\nNow, Team B Playings: " << endl;
        cout << "Initial Position: " << x << "," << y << endl;
        while (!team2.getIsGoalMade())
        {

            cout << "Enter hit direction: " << endl;
            cin >> direction;
            team2.getRobot()->hitBall(x, y, direction);
            cout << "\nAfter " << team2.getTeamName() << " Hit: " << x << "," << y << endl;

            if (x > 0 && x <= goalPosition.getX())
            {
                ball.setX(x);
            }
            else
            {
                x = ball.getX();
            }
            if (y > 0 && y <= goalPosition.getY())
            {
                ball.setY(y);
            }
            else
            {
                y = ball.getY();
            }
            if (goalPosition.isGoalReached(ball.getX(), ball.getY()))
            {
                ball.setX(0);
                ball.setY(0);
                x = 0;
                y = 0;
                team1.setIsGoalMade(true);
                cout << "Goal Reached!" << endl;
                cout << "Number of Hits: " << team2.getRobot()->getHits() << endl;
                break;
            }
        }
        declareWinner();
    }

    void declareWinner()
    {
        cout << "Team A : " << team1.getRobot()->getHits() << endl;
        cout << "Team B : " << team2.getRobot()->getHits() << endl;
        if (team1.getRobot()->getHits() < team2.getRobot()->getHits())
        {
            cout << team1.getTeamName() << " wins!" << endl;
        }
        else if (team1.getRobot()->getHits() > team2.getRobot()->getHits())
        {
            cout << team2.getTeamName() << " wins!" << endl;
        }
        else
        {
            cout << "Match tied!" << endl;
        }
        team1.getRobot()->setHits(0);
        team2.getRobot()->setHits(0);
    }
};

int main()
{
    Robot r1("Alpha");
    Robot r2("Beta");

    Team teamA(&r1, "Team A");
    Team teamB(&r2, "Team B");

    Game game(teamA, teamB);
    game.startGame();
    game.play();

    return 0;
}
