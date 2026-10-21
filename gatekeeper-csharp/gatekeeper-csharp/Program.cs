

using Grpc.Net.Client;
using ScoreEngine.Gatekeeper.Grpc;

Console.WriteLine("=== ScoreEngine Gatekeeper (.NET 10) ===");

using var channel = GrpcChannel.ForAddress("http://localhost:50051");
var client = new ScoreService.ScoreServiceClient(channel);

var request = new ScoreEventRequest
{
    SequenceId = 1,
    SwitchCode = "START_BUTTON",
    TimestampNs = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds() * 1_000_000,
    Signature = "VALID_SECRET"
};

Console.WriteLine($"[C# Gatekeeper] Prêt à envoyer l'événement: {request.SwitchCode}");