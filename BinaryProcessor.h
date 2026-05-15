#pragma once
#include "ImageProcessor.h"

// =============================================
// BinaryProcessor - 이진화 처리기
//
// [역할]
//   - 흑백 이미지의 각 픽셀을 0(검정) 또는 255(흰색)로 변환
//   - threshold 기준으로 밝으면 255, 어두우면 0
//
// [멤버 변수]
//   threshold : 이진화 기준값 (0~255, 보통 128 사용)
// =============================================
class BinaryProcessor : public ImageProcessor {
public:
    // 생성자 - 임계값 설정
    BinaryProcessor(unsigned char threshold);

    void Process(ImageData *img) override;

private:
    unsigned char threshold;
};
