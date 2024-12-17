#include <iostream>
#include <vector>

// 스킬 인터페이스 (순수 가상 함수)
class Skill {
public:
    virtual void use() = 0;  // 순수 가상 함수 (각각의 스킬에서 구현되어야 함)
    virtual ~Skill() {}  // 가상 소멸자
};

// 공격 스킬 클래스
class AttackSkill : public Skill {
public:
    void use() override {
        std::cout << "강력한 공격을 실행합니다!" << std::endl;
    }
};

// 치유 스킬 클래스
class HealSkill : public Skill {
public:
    void use() override {
        std::cout << "플레이어의 체력을 회복합니다!" << std::endl;
    }
};

// 방어 스킬 클래스
class DefenseSkill : public Skill {
public:
    void use() override {
        std::cout << "방어력을 강화합니다!" << std::endl;
    }
};

// 스킬을 사용하는 캐릭터 클래스
class Character {
private:
    std::vector<Skill*> skills;  // 캐릭터가 가진 스킬들

public:
    // 스킬 추가
    void addSkill(Skill* skill) {
        skills.push_back(skill);
    }

    // 모든 스킬 사용
    void useSkills() {
        for (auto skill : skills) {
            skill->use();
        }
    }

    ~Character() {
        // 동적으로 생성된 스킬 메모리 해제
        for (auto skill : skills) {
            delete skill;
        }
    }
};

int main() {
    Character hero;

    // 다양한 스킬을 캐릭터에 추가
    hero.addSkill(new AttackSkill());
    hero.addSkill(new HealSkill());
    hero.addSkill(new DefenseSkill());

    // 캐릭터가 가진 모든 스킬 사용
    hero.useSkills();

    return 0;
}