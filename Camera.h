#pragma once
#include "ImageProcessor.h"
#include <vector>
using namespace std;

// =============================================
// Camera - 카메라 및 이미지 처리 파이프라인 관리
//
// [역할]
//   - 처리기(ImageProcessor)들을 순서대로 등록
//   - 프레임이 들어오면 등록된 순서대로 처리기 실행
//
// [핵심 개념]
//   pipeline : ImageProcessor* 포인터 벡터
//              → 서로 다른 타입의 처리기를 부모 포인터로 묶어서 관리
//              → 동적 바인딩으로 각자 맞는 Process 함수 호출
//
// [실제 카메라 연동]
//   실제 카메라 SDK에서 프레임이 들어오면 OnImageCallback 자동 호출
//   지금은 main에서 직접 호출해서 시뮬레이션
// =============================================
class Camera {
public:
    Camera();
    ~Camera();  // 소멸자에서 pipeline 메모리 전부 해제

    // 처리기 등록 - 힙에 생성한 처리기 포인터를 pipeline에 추가
    void AddProcessor(ImageProcessor *processor);

    // 프레임 수신 콜백 - 등록된 처리기 순서대로 실행
    void OnImageCallback(ImageData *img);

private:
    // 포인터 벡터: 처리기들을 순서대로 관리
    // vector는 크기가 동적으로 늘어나는 배열 (파이썬 리스트와 같음)
    vector<ImageProcessor*> pipeline;
};
