#ifndef ADDENTITYEVENT_H
#define ADDENTITYEVENT_H

#include "cad/const.h"

#include "cad/base/cadentity.h"

namespace lc {
    /**
     * Event that get's emited when a new entity was added to the document
     * @param cadEntity
     */
    class AddEntityEvent {
        public:
            AddEntityEvent(const QString& layerName, CADEntityPtr cadEntity) {
                _cadEntity = cadEntity;
                _layerName = layerName;
            }

            CADEntityPtr entity() const {
                return _cadEntity;
            }

            QString layerName() const {
                return _layerName;
            }

        private:
            QString _layerName;
            CADEntityPtr _cadEntity;
    };
}
#endif // ADDENTITYEVENT_H