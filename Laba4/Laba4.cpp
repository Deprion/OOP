#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Device
{
private:
	string name, manufacturer;
	int power;
public:
	void InputPower(int _power) { power = _power; };
	void OutputInfo()
	{
		cout << "name:" << name << endl << "power:" << power << endl << "manufacturer:" << manufacturer << endl;
	}
	Device(string _name, int _power, string _manufacturer) { name = _name, power = _power, manufacturer = _manufacturer; }
	~Device() {};
};

class Sound
{
private:
	int frequency, volume;
public:
	void InputVolume(int _volume) { volume = _volume; };
	void OutputInfo(){ cout << "frequency:" << frequency << endl << "volume:" << volume << endl; }
	Sound(int _frequency, int _volume) { frequency = _frequency, volume = _volume; }
	~Sound() {};
};

class Siren : Device, Sound
{
public:
	Siren(string _name, int _power, string _manufacturer, int _frequency, int _volume) :
		Device(_name, _power, _manufacturer), Sound(_frequency, _volume) {};
};
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Device:" << endl;
	Device* dev = new Device("Rock", 10, "Germany");
	dev->OutputInfo();
	cout << "Sound:" << endl;
	Sound* sound = new Sound(144, 8);
	sound->OutputInfo();
	cout << "Siren:" << endl;
	Siren* siren = new Siren("Rock", 10, "Germany", 144, 8);
	((Device*)siren)->Device::OutputInfo();
	((Sound*)siren)->Sound::OutputInfo();
	delete dev;
	delete sound;
	delete siren;
}