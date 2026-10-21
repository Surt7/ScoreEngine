#pragma once
#include <score_engine.grpc.pb.h>

#include "core/ScoreEngine.h"

class ScoreServiceImpl final : public scoreengine::ScoreService::Service {
public:
    explicit ScoreServiceImpl(ScoreEngine &engine);

    grpc::Status ProcessEvent(
        grpc::ServerContext *context,
        const scoreengine::ScoreEventRequest *request,
        scoreengine::ScoreEventReply *reply
    ) override;

private :
    ScoreEngine &engine_;
};
