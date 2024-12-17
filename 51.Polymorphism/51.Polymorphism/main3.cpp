#include <iostream>
#include <vector>

// ��ų �������̽� (���� ���� �Լ�)
class Skill {
public:
    virtual void use() = 0;  // ���� ���� �Լ� (������ ��ų���� �����Ǿ�� ��)
    virtual ~Skill() {}  // ���� �Ҹ���
};

// ���� ��ų Ŭ����
class AttackSkill : public Skill {
public:
    void use() override {
        std::cout << "������ ������ �����մϴ�!" << std::endl;
    }
};

// ġ�� ��ų Ŭ����
class HealSkill : public Skill {
public:
    void use() override {
        std::cout << "�÷��̾��� ü���� ȸ���մϴ�!" << std::endl;
    }
};

// ��� ��ų Ŭ����
class DefenseSkill : public Skill {
public:
    void use() override {
        std::cout << "������ ��ȭ�մϴ�!" << std::endl;
    }
};

// ��ų�� ����ϴ� ĳ���� Ŭ����
class Character {
private:
    std::vector<Skill*> skills;  // ĳ���Ͱ� ���� ��ų��

public:
    // ��ų �߰�
    void addSkill(Skill* skill) {
        skills.push_back(skill);
    }

    // ��� ��ų ���
    void useSkills() {
        for (auto skill : skills) {
            skill->use();
        }
    }

    ~Character() {
        // �������� ������ ��ų �޸� ����
        for (auto skill : skills) {
            delete skill;
        }
    }
};

int main() {
    Character hero;

    // �پ��� ��ų�� ĳ���Ϳ� �߰�
    hero.addSkill(new AttackSkill());
    hero.addSkill(new HealSkill());
    hero.addSkill(new DefenseSkill());

    // ĳ���Ͱ� ���� ��� ��ų ���
    hero.useSkills();

    return 0;
}