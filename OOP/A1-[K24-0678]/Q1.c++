#include <iostream>
using namespace std;

class Mentor;

class Skill
{
    int SkillId;
    string SkillName;
    string Description;

public:
    Skill()
    {
        SkillId = 0;
        SkillName = "";
        Description = "";
    }
    Skill(int SkillId, string SkillName, string Description)
    {
        this->SkillId = SkillId;
        this->SkillName = SkillName;
        this->Description = Description;
    }
    void setSkillId(int SkillId)
    {
        this->SkillId = SkillId;
    }

    int getSkillId()
    {
        return SkillId;
    }

    void setSkillName(string SkillName)
    {
        this->SkillName = SkillName;
    }

    string getSkillName()
    {
        return SkillName;
    }

    void setDescription(string Description)
    {
        this->Description = Description;
    }

    string getDescription()
    {
        return Description;
    }
    void showSkillDetails()
    {
        cout << "Skill ID: " << getSkillId() << endl;
        cout << "Skill Name: " << getSkillName() << endl;
        cout << "Description: " << getDescription() << endl;
    }
    void updateSkillDescription(string skillDescription)
    {
        this->Description = skillDescription;
    }
};

class Sport
{
    int sportId;
    string sportname;
    string description;
    Skill *requiredSkills;
    int ReqSkillSize;

public:
    Sport()
    {
        this->requiredSkills = nullptr;
        this->sportId = 0;
        this->sportname = "";
        this->description = "";
        this->ReqSkillSize = 0;
    }
    Sport(int sportId, string sportname, string description, Skill *arr, int reqSkillSize)
    {
        this->requiredSkills = new Skill[reqSkillSize];
        this->sportId = sportId;
        this->sportname = sportname;
        this->description = description;
        this->ReqSkillSize = reqSkillSize;
        for (int i = 0; i < reqSkillSize; i++)
        {
            this->requiredSkills[i] = arr[i];
        }
    }
    ~Sport()
    {
        delete[] requiredSkills;
    }

    void setSportId(int sportId)
    {
        this->sportId = sportId;
    }

    int getSportId()
    {
        return sportId;
    }

    void setSportname(string sportname)
    {
        this->sportname = sportname;
    }

    string getSportname()
    {
        return sportname;
    }

    void setDescription(string description)
    {
        this->description = description;
    }

    string getDescription()
    {
        return description;
    }

    void setRequiredSkills(Skill *requiredSkills)
    {
        this->requiredSkills = requiredSkills;
    }

    Skill *getRequiredSkills()
    {
        return requiredSkills;
    }
    void addSkill(Skill required)
    {
        Skill *Skills = new Skill[ReqSkillSize + 1];

        for (int i = 0; i < ReqSkillSize; i++)
        {
            Skills[i] = requiredSkills[i];
        }

        Skills[ReqSkillSize] = required;

        delete[] requiredSkills;
        requiredSkills = Skills;
        ReqSkillSize++;
    }

    void removeSkill(int ID)
    {
        if (ReqSkillSize == 0)
            return;

        int index = -1;

        for (int i = 0; i < ReqSkillSize; i++)
        {
            if (requiredSkills[i].getSkillId() == ID)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
            return;

        Skill *Skills = new Skill[ReqSkillSize - 1];

        for (int i = 0, j = 0; i < ReqSkillSize; i++)
        {
            if (i != index)
            {
                Skills[j++] = requiredSkills[i];
            }
        }

        delete[] requiredSkills;
        requiredSkills = Skills;
        ReqSkillSize--;
    }
};

class Student
{
    int studentId;
    string name;
    int age;
    Sport **sportsInterests;
    Mentor *mentorAssigned;
    int SportSize;

public:
    Student()
    {
        studentId = 0;
        name = "";
        age = 0;
        sportsInterests = nullptr;
        mentorAssigned = nullptr;
        SportSize = 0;
    }
    Student(int studentId, string name, int age, Sport **Sports, int SportSize, Mentor *Mentorptr)
    {
        this->studentId = studentId;
        this->name = name;
        this->age = age;
        this->sportsInterests = new Sport *[SportSize];
        for (int i = 0; i < SportSize; i++)
            this->sportsInterests[i] = Sports[i];
        this->mentorAssigned = Mentorptr;
        this->SportSize = SportSize;
    }
    ~Student()
    {
        delete[] sportsInterests; // Free dynamically allocated memory
    }

    void setStudentId(int studentId)
    {
        this->studentId = studentId;
    }

    int getStudentId()
    {
        return studentId;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return age;
    }

    void setSportsInterests(Sport **sportsInterests)
    {
        this->sportsInterests = sportsInterests;
    }

    Sport **getSportsInterests()
    {
        return sportsInterests;
    }

    void setMentorAssigned(Mentor *mentorAssigned)
    {
        this->mentorAssigned = mentorAssigned;
    }
    void veiwDetails();
    void updateSportInterests(Sport **s, int ID)
    {
        if (ID >= 0 && ID < SportSize)
        {
            sportsInterests[ID]->setSportname(s[ID]->getSportname());
            sportsInterests[ID]->setDescription(s[ID]->getDescription());
        }
    }
    void registerForMentor(Mentor *m)
    {
        setMentorAssigned(m);
    }
    Mentor *getMentorAssigned()
    {
        return mentorAssigned;
    }
};

class Mentor
{
    int mentorId;
    string name;
    int maxLearners;
    Sport **sportsExpertise;
    int SportSize;
    Student **assignedLearners;
    int LeanerSize;

public:
    Mentor(int mentorId, string name, int maxLearners, Sport **Sports, int SportsSize, Student **Learners, int LeanerSize)
    {
        this->mentorId = mentorId;
        this->name = name;
        this->maxLearners = maxLearners;
        this->sportsExpertise = new Sport *[SportsSize];
        for (int i = 0; i < SportsSize; i++)
        {
            this->sportsExpertise[i] = Sports[i];
        }
        this->SportSize = SportsSize;
        this->assignedLearners = new Student *[maxLearners]; // Initialize to maxLearners size
        for (int i = 0; i < LeanerSize; i++)
        {
            this->assignedLearners[i] = Learners[i];
        }
        this->LeanerSize = LeanerSize;
    }
    Mentor()
    {
        this->mentorId = 0;
        this->name = "";
        this->maxLearners = 0;
        this->sportsExpertise = nullptr;
        this->SportSize = 0;
        this->assignedLearners = nullptr;
        this->LeanerSize = 0;
    }
    ~Mentor()
    {
        delete[] sportsExpertise; // Free dynamically allocated memory
        delete[] assignedLearners;
    }

    void setMentorId(int mentorId)
    {
        this->mentorId = mentorId;
    }

    int getMentorId()
    {
        return mentorId;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setMaxLearners(int maxLearners)
    {
        this->maxLearners = maxLearners;
    }

    int getMaxLearners()
    {
        return maxLearners;
    }

    void setSportsExpertise(Sport **sportsExpertise)
    {
        this->sportsExpertise = sportsExpertise;
    }

    Sport **getSportsExpertise()
    {
        return sportsExpertise;
    }

    void setAssignedLearners(Student **assignedLearners)
    {
        this->assignedLearners = assignedLearners;
    }

    Student **getAssignedLearners()
    {
        return assignedLearners;
    }
    void assignLearner(Student *s)
    {
        if (LeanerSize < maxLearners)
        {
            assignedLearners[LeanerSize] = s;
            LeanerSize++;
        }
    }
    void viewLearner()
    {
        if (assignedLearners == nullptr || LeanerSize == 0)
        {
            cout << "No learners assigned.\n";
            return;
        }
        for (int i = 0; i < LeanerSize; i++)
        {
            cout << "Student : " << i + 1 << endl;
            cout << "Student ID: " << assignedLearners[i]->getStudentId() << endl;
            cout << "Name: " << assignedLearners[i]->getName() << endl;
            cout << "Age: " << assignedLearners[i]->getAge() << endl;
            cout << "\n\n";
        }
    }
    void provideGuidance()
    {
        cout << "\nGuidance Provided...\n";
    }
};
void Student::veiwDetails()
{
    if (mentorAssigned)
    {
        cout << "\nMentor ID: " << mentorAssigned->getMentorId() << endl;
        cout << "Mentor Name: " << mentorAssigned->getName() << endl;
    }
    else
    {
        cout << "No mentor assigned.\n";
    }
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int noSkills;
    cout << "Enter the number of skills: ";
    cin >> noSkills;
    cin.ignore();

    Skill *skills = new Skill[noSkills];
    for (int i = 0; i < noSkills; i++)
    {
        int id;
        string name, description;
        cout << "Enter Skill ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Skill Name: ";
        getline(cin, name);
        cout << "Enter Skill Description: ";
        getline(cin, description);
        skills[i] = Skill(id, name, description);
    }

    int noSports;
    cout << "Enter the number of sports: ";
    cin >> noSports;
    cin.ignore();

    Sport **sports = new Sport *[noSports];
    for (int i = 0; i < noSports; i++)
    {
        int id, skillCount;
        string name, description;
        cout << "Enter Sport ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Sport Name: ";
        getline(cin, name);
        cout << "Enter Sport Description: ";
        getline(cin, description);

        cout << "Enter number of skills for this sport: ";
        cin >> skillCount;
        cin.ignore();

        Skill *sportSkills = new Skill[skillCount];
        for (int j = 0; j < skillCount; j++)
        {
            int skillIndex;
            cout << "Enter index of skill from available skills (0 to " << noSkills - 1 << "): ";
            cin >> skillIndex;
            sportSkills[j] = skills[skillIndex];
        }

        sports[i] = new Sport(id, name, description, sportSkills, skillCount);
    }

    int noMentors;
    cout << "Enter number of mentors: ";
    cin >> noMentors;
    cin.ignore();

    Mentor **mentors = new Mentor *[noMentors];
    for (int i = 0; i < noMentors; i++)
    {
        int id, expertise;
        string name;
        cout << "Enter Mentor ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Mentor Name: ";
        getline(cin, name);
        cout << "Enter expertise level: ";
        cin >> expertise;
        cin.ignore();

        mentors[i] = new Mentor(id, name, expertise, sports, noSports, nullptr, 0);
    }

    int noStudents;
    cout << "Enter number of students: ";
    cin >> noStudents;
    cin.ignore();

    Student **students = new Student *[noStudents];
    for (int i = 0; i < noStudents; i++)
    {
        int id, age;
        string name;
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Age: ";
        cin >> age;
        cin.ignore();

        int mentorIndex;
        cout << "Enter index of mentor for this student (0 to " << noMentors - 1 << ") or -1 for none: ";
        cin >> mentorIndex;
        cin.ignore();

        Mentor *assignedMentor = (mentorIndex >= 0) ? mentors[mentorIndex] : nullptr;
        students[i] = new Student(id, name, age, sports, noSports, assignedMentor);

        if (assignedMentor)
        {
            assignedMentor->assignLearner(students[i]);
        }
    }

    cout << "\n--- Mentor's Learners ---\n";
    for (int i = 0; i < noMentors; i++)
    {
        mentors[i]->viewLearner();
    }

    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < noStudents; i++)
    {
        students[i]->veiwDetails();
    }

    cout << "\n--- Mentor Guidance ---\n";
    for (int i = 0; i < noMentors; i++)
    {
        mentors[i]->provideGuidance();
    }

    cout << "\n--- Updating Student Interests ---\n";
    for (int i = 0; i < noStudents; i++)
    {
        students[i]->updateSportInterests(sports, noSports);
    }

    for (int i = 0; i < noStudents; i++)
        delete students[i];
    delete[] students;

    for (int i = 0; i < noMentors; i++)
        delete mentors[i];
    delete[] mentors;

    for (int i = 0; i < noSports; i++)
        delete sports[i];
    delete[] sports;

    delete[] skills;

    return 0;
}
