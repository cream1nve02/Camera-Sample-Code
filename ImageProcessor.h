#pragma once
#include "ImageData.h"

// =============================================
// ImageProcessor - 이미지 처리기 부모 클래스 (인터페이스)
//
// [역할]
//   - 모든 처리기의 공통 타입 역할
//   - Camera의 pipeline 벡터에 묶어서 관리하기 위해 필요
//   - 자식 클래스가 반드시 Process를 구현하도록 강제
//
// [순수 가상함수 = 0]
//   - 구현 없이 이름만 선언
//   - 자식이 override로 반드시 구현해야 함
//   - 이 클래스는 직접 객체 생성 불가 (추상 클래스)
//
// [virtual 소멸자]
//   - 부모 포인터로 delete 할 때 자식 소멸자까지 호출되게 함
//   - 없으면 자식 소멸자가 안 불려 메모리 누수 발생
// =============================================
class ImageProcessor {
public:
    virtual void Process(ImageData *img) = 0;
    virtual ~ImageProcessor() {}
};
