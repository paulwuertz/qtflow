#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QSettings>
#include <QProcess>
#include <QFileDevice>
#include <QCommandLineParser>

class IProject
{
public:
	IProject() {}
	virtual ~IProject() {}
	virtual bool create(QString) { return false; }
	virtual bool valuedump(QString, QProcess* = new QProcess) { return false; }

	virtual bool synthesis(QString, QProcess* = new QProcess) { return false; }
	virtual bool synthesis() { return false; }

	virtual bool timing(QString, QProcess* = new QProcess) { return false; }

	virtual bool placement(QString, QProcess* = new QProcess) { return false; }

	virtual bool routing(QString, QProcess* = new QProcess) { return false; }

	virtual bool buildAll(QString, QProcess* = new QProcess) { return false; }
};

class Project : public IProject
{
public:
	Project(QSettings *settings, QString path);
	~Project();
	bool create(QString);
	bool synthesis();
	bool synthesis(QString ident, QProcess* = new QProcess);
	bool timing(QString ident, QProcess* = new QProcess);
	bool placement(QString ident, QProcess* = new QProcess);
	bool routing(QString ident, QProcess* = new QProcess);
	bool buildAll(QString ident, QProcess* = new QProcess);
	bool prepareStep(QString path);
	void setTechnology(QString tech);
	void setProcess(QString proc);
	void setTopLevel(QString mod);
	void setTestBench(QString mod);

	QString getSourceDir();
	QString getTopLevel();
	QString getRootDir();
	QString getTestBench();
	QString getTechnology();
	QString getProcess();

private:
	QSettings *settings;
	QSettings *project_settings;
	QString rootdir;

	QFileDevice::Permissions executable;
};

#endif // PROJECT_H
