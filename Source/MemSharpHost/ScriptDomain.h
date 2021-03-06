#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Threading::Tasks;
using namespace System::Collections::Generic;
using namespace MemSharpCommon;

ref class ScriptDomain : public MarshalByRefObject
{
public:
	ScriptDomain();

	static ScriptDomain^ Load(String^ path);
	static void Unload(ScriptDomain ^% domain);

	void Start();

	virtual Object^ InitializeLifetimeService() override;
private:
	bool LoadScript(String^ filename);
	bool LoadAssembly(String^ filename);
	bool InitializeAssembly(Assembly^ assembly);
	Script^ CreateScriptInstance(Type^ scriptType);

public:
	property AppDomain^ Domain;
	List<Script^>^ runningScripts;

private:
	List<Tuple<String^, Type^>^>^ scriptTypes;

};
