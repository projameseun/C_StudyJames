#include <iostream>
#include <vector>

// 기본 Skill 클래스 (다형성의 기반)
class Skill {
public:
    // 가상 함수로 선언되어 각 스킬 클래스에서 오버라이딩 가능
    virtual void cast() const {
        std::cout << "기본 스킬을 사용합니다!" << std::endl;
    }

    virtual ~Skill() {}
};

// Fireball 클래스 (Skill 클래스에서 파생)
class Fireball : public Skill {
public:
    void cast() const override {
        std::cout << "파이어볼을 던졌습니다!" << std::endl;
    }
};

// IceBlast 클래스 (Skill 클래스에서 파생)
class IceBlast : public Skill {
public:
    void cast() const override {
        std::cout << "아이스블래스트를 시전했습니다!" << std::endl;
    }
};

// Heal 클래스 (Skill 클래스에서 파생)
class Heal : public Skill {
public:
    void cast() const override {
        std::cout << "힐링을 시전했습니다!" << std::endl;
    }
};

// 스킬을 사용하는 함수
void useSkill(Skill* skill) {
    skill->cast();  // 다형성: skill 객체가 실제 어떤 타입이냐에 따라 적절한 cast() 호출
}

int main() {
    // 각기 다른 스킬 객체들 생성
    Fireball fireball;
    IceBlast iceBlast;
    Heal heal;

    // 다형성을 사용하여 여러 스킬을 동일한 방식으로 사용
    std::vector<Skill*> skills;
    skills.push_back(&fireball);
    skills.push_back(&iceBlast);
    skills.push_back(&heal);

    // 각 스킬을 순차적으로 시전
    for (Skill* skill : skills) {
        useSkill(skill);  // 다형성을 통해 각기 다른 스킬을 동일한 방식으로 호출
    }

    return 0;
}