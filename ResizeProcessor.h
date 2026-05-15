#pragma once
#include "ImageProcessor.h"

// =============================================
// ResizeProcessor - 이미지 크기 조절 처리기
//
// [역할]
//   - 입력 이미지를 지정한 해상도로 변환
//
// [멤버 변수]
//   targetW, targetH : 목표 해상도 (생성자에서 설정)
// =============================================
class ResizeProcessor : public ImageProcessor {
public:
    // 생성자 - 목표 해상도를 받아 멤버변수에 저장
    ResizeProcessor(int targetW, int targetH);

    // Process 오버라이딩 - 실제 리사이즈 처리
    // override 키워드: 부모 함수 재정의 명시 (오타 방지)
    void Process(ImageData *img) override;

private:
    int targetW;
    int targetH;
};
