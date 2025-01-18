#ifndef TIMESTEP_H
#define TIMESTEP_H


namespace Bell
{
    class Timestep
	{
	private:
		float m_Time;

    public:
		Timestep(float time = 0.0f)
			: m_Time(time)
		{
		}

		operator float() const { return m_Time; }

		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }
	
	};
}

#endif //TIMESTEP_H