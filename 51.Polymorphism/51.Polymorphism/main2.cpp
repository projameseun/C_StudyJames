#include <iostream>
#include <vector>

// �⺻ Skill Ŭ���� (�������� ���)
class Skill {
public:
    // ���� �Լ��� ����Ǿ� �� ��ų Ŭ�������� �������̵� ����
    virtual void cast() const {
        std::cout << "�⺻ ��ų�� ����մϴ�!" << std::endl;
    }

    virtual ~Skill() {}
};

// Fireball Ŭ���� (Skill Ŭ�������� �Ļ�)
class Fireball : public Skill {
public:
    void cast() const override {
        std::cout << "���̾�� �������ϴ�!" << std::endl;
    }
};

// IceBlast Ŭ���� (Skill Ŭ�������� �Ļ�)
class IceBlast : public Skill {
public:
    void cast() const override {
        std::cout << "���̽�����Ʈ�� �����߽��ϴ�!" << std::endl;
    }
};

// Heal Ŭ���� (Skill Ŭ�������� �Ļ�)
class Heal : public Skill {
public:
    void cast() const override {
        std::cout << "������ �����߽��ϴ�!" << std::endl;
    }
};

// ��ų�� ����ϴ� �Լ�
void useSkill(Skill* skill) {
    skill->cast();  // ������: skill ��ü�� ���� � Ÿ���̳Ŀ� ���� ������ cast() ȣ��
}

int main() {
    // ���� �ٸ� ��ų ��ü�� ����
    Fireball fireball;
    IceBlast iceBlast;
    Heal heal;

    // �������� ����Ͽ� ���� ��ų�� ������ ������� ���
    std::vector<Skill*> skills;
    skills.push_back(&fireball);
    skills.push_back(&iceBlast);
    skills.push_back(&heal);

    // �� ��ų�� ���������� ����
    for (Skill* skill : skills) {
        useSkill(skill);  // �������� ���� ���� �ٸ� ��ų�� ������ ������� ȣ��
    }

    return 0;
}