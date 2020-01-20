class WaveTime
{
public:
	const int fearTime;
	const int firstWaveRetreat;
	const int firstWaveAttack;
	const int secondWaveRetreat;
	const int secondWaveAttack;
	const int thirdWaveRetreat;
	const int thirdWaveAttack;
	const int fourthWaveRetreat;
	WaveTime(const int fearTime, const int firstWaveRetreat, const int firstWaveAttack, const int secondWaveRetreat,
		const int secondWaveAttack, const int thirdWaveRetreat, const int thirdWaveAttack, const int fourthWaveRetreat) : 
		fearTime(fearTime), firstWaveRetreat(firstWaveRetreat), firstWaveAttack(firstWaveAttack), secondWaveRetreat(secondWaveRetreat), 
		secondWaveAttack(secondWaveAttack), thirdWaveRetreat(thirdWaveRetreat), thirdWaveAttack(thirdWaveAttack), fourthWaveRetreat(fourthWaveRetreat) {}
};