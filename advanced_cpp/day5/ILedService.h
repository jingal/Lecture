struct ILedService
{
	virtual void LedOn() = 0;
	virtual void LedOff() = 0;
	virtual ~ILedService() {}
};
