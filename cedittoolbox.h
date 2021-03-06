#ifndef CEDITTOOLBOX_H
#define CEDITTOOLBOX_H

#include <QWidget>
#include <QAction>
#include <QToolButton>
#include <QToolBar>
#include "cobjectpicker.h"

#include "cbrushtool.h"
#include "clinetool.h"
#include "cfilltool.h"

class CMapWidget;

class CEditToolbox : public QWidget {
	Q_OBJECT
	
public:
	explicit CEditToolbox(QWidget *parent = 0);
	~CEditToolbox();

	void setup(CMapWidget *mw);
	void reloadPatches();
	void cleanup();

private:
	QToolBar *m_toolbar;
	QActionGroup *m_toolActions;
	QAction *m_brushToolAction, *m_lineToolAction;
	QAction *m_fillToolAction;

	CObjectPicker *m_objectPicker;

	CMapWidget *m_mapWidget;

	CBrushTool *m_brushTool;
	CLineTool *m_lineTool;
	CFillTool *m_fillTool;

	void setupKeyActions();

	QAction *m_prevObjAction, *m_nextObjAction;
	QAction *m_prev8ObjAction, *m_next8ObjAction;

private slots:
	void toolActionActivated(QAction *action);

public:
	CObjectPicker *objectPicker() const { return m_objectPicker; }
};

#endif // CEDITTOOLBOX_H
